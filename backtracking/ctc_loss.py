import logging
from typing import MutableMapping, Tuple

import torch
import editdistance as ed

from .loss import Loss, add_loss
from ..data import Batch, Field

logger = logging.getLogger(__name__)


def distance(xs: torch.Tensor, ys: torch.Tensor, xlen: torch.Tensor, ylen: torch.Tensor, blank: int = 0) -> float:
    xs = xs.cpu().numpy()
    ys = ys.cpu().numpy()
    xlen = xlen.cpu().numpy()
    ylen = ylen.cpu().numpy()
    def path(x):
        prev = blank
        seq = []
        for i in x:
            if i not in [blank, prev]:
                seq.append(i)
            prev = i
        return seq
    err = 0
    for x, y, xl, yl in zip(xs, ys, xlen, ylen):
        err += ed.eval(path(x[:int(xl)]), y[:int(yl)])
    return err


@add_loss('ctc')
class CTCLoss(Loss):
    """A wrapper for Pytorch's builtin CTC Loss

    .. note:: We decided to move from warp-ctc to pytorch ctc for clean dependency

    Args:
        output (Field): model output, with tensor of shape(B, T, D)
        data_batch (dict): the data_batch from batch loader.
                           label (Field), feat (Field)
    """

    def __init__(self, size_average=False, blank: int = 0):
        super().__init__()
        if size_average:
            logger.warning('We are now averaging over #token instead of #utterance')
            reduction = 'mean'
        else:
            reduction = 'sum'
        self.loss_kernel = torch.nn.CTCLoss(blank=blank, reduction=reduction, zero_infinity=True)

    def forward(self, output: Field, data_batch: Batch) -> Tuple[torch.Tensor, MutableMapping[str, float]]:
        assert output.length is not None, 'Model must produce Field output with length for ctc'
        label = data_batch['label']
        log_prob = output.tensor.transpose(0, 1).log_softmax(dim=2)  # T, N, C
        loss = self.loss_kernel(log_prob, label.tensor, output.length, label.length)
        loss_statistics = self._get_statistics(loss, output, label)
        return loss, loss_statistics

    def _get_statistics(self, loss: torch.Tensor, output: Field, label: Field) -> MutableMapping[str, float]:
        utterances = len(label.length)
        loss_item = loss.item()  # utterance level ctc loss * utterances
        _, prediction = torch.max(output.tensor, 2)
        error_labels = distance(prediction, label.tensor, output.length, label.length, self.loss_kernel.blank)
        labels = label.length.sum().item()
        correct_labels = labels - error_labels
        loss_statistics = {
            'loss': loss_item,
            'correct_labels': correct_labels,
            'total_labels': labels,
            'total_frames': sum(output.length).item(),
            'utterances': utterances,
        }

        return loss_statistics

    def log_stat(self, reduced_stat: MutableMapping[str, float]):
        """Convert the reduced statistics into a log line"""
        token_accuracy = reduced_stat['correct_labels'] / reduced_stat['total_labels']
        loss_per_frame = reduced_stat['loss'] / reduced_stat['total_frames']
        return {
            'token_acc': token_accuracy * 100,
            'loss': loss_per_frame,
        }
