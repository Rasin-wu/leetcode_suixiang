import logging
from typing import MutableMapping, Tuple

import torch
import editdistance as ed

from asr.loss.loss import Loss, add_loss
from asr.data import Batch, Field

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


@add_loss('pfctc')
class PeakFirstCTCLoss(Loss):
    """A wrapper for Pytorch's builtin CTC Loss with peak-first regularization.

    .. note:: We decided to move from warp-ctc to pytorch ctc for clean dependency

    Args:
        output (Field): model output, with tensor of shape(B, T, D)
        data_batch (dict): the data_batch from batch loader.
                           label (Field), feat (Field)
    """

    def __init__(self, size_average=False, blank: int = 0, T: float = 10.0, alpha: float =1.0):
        super().__init__()
        if size_average:
            logger.warning('We are now averaging over #token instead of #utterance')
            reduction = 'mean'
        else:
            reduction = 'sum'
        self.loss_kernel = torch.nn.CTCLoss(blank=blank, reduction=reduction, zero_infinity=True)
        self.T = T
        self.alpha = alpha

    def forward(self, output: Field, data_batch: Batch) -> Tuple[torch.Tensor, MutableMapping[str, float]]:
        assert output.length is not None, 'Model must produce Field output with length for ctc'
        label = data_batch['label']
        log_prob = output.tensor.transpose(0, 1).log_softmax(dim=2)  # T, N, C
        ctc_loss = self.loss_kernel(log_prob, label.tensor, output.length, label.length)
        reg = self._cal_regularization(output, self.T)
        loss = ctc_loss + self.alpha * reg
        loss_statistics = self._get_statistics(loss, output, label)
        loss_statistics['ctc_loss'] = ctc_loss.item()
        loss_statistics['reg_item'] = reg.item()
        return loss, loss_statistics
    
    def _cal_regularization(self, output: Field, T) -> torch.Tensor:
        probs = torch.softmax(output.tensor/T, dim=2).transpose(0, 1)  # T, B, D
        p1 = probs[3:-1]
        p2 = probs[4:]

        max_len = torch.clamp(output.length - 4, min=0)
        masks = self.make_pad_mask(max_len).transpose(0, 1).unsqueeze(-1).to(probs.device) # T, B, 1
        masks = ~masks
        reg = (p2 * (p2 / p1).log() * masks).sum()
        return reg

    @staticmethod
    def make_pad_mask(lengths: torch.Tensor, max_len: int = 0) -> torch.Tensor:
        """Make mask tensor containing indices of padded part.

        See description of make_non_pad_mask.

        Args:
            lengths (torch.Tensor): Batch of lengths (B,).
        Returns:
            torch.Tensor: Mask tensor containing indices of padded part.

        Examples:
            >>> lengths = [5, 3, 2]
            >>> make_pad_mask(lengths)
            masks = [[0, 0, 0, 0 ,0],
                    [0, 0, 0, 1, 1],
                    [0, 0, 1, 1, 1]]
        """
        batch_size = lengths.size(0)
        max_len = max_len if max_len > 0 else lengths.max().item()
        seq_range = torch.arange(0,
                                max_len,
                                dtype=torch.int64,
                                device=lengths.device)
        seq_range_expand = seq_range.unsqueeze(0).expand(batch_size, max_len)
        seq_length_expand = lengths.unsqueeze(-1)
        mask = seq_range_expand >= seq_length_expand
        return mask

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
        ctc_loss_per_utt = reduced_stat['ctc_loss'] / reduced_stat['utterances']
        reg_item_per_utt = reduced_stat['reg_item'] / reduced_stat['utterances']
        return {
            'token_acc': token_accuracy * 100,
            'loss': loss_per_frame,
            'ctc_loss_per_utt': ctc_loss_per_utt,
            'reg_item_per_utt': reg_item_per_utt
        }
