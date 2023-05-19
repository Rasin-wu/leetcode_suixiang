#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class ListNode:
    def __init__(self, val = 0, next = None):
        self.val = val
        self.next = next


class LinkList(object):
    def __init__(self):
        self.head = None

    def initList(self, data: List[int]):

        self.head = ListNode(data[0])
        #初始化p指向头节点
        p = self.head
        
        for i in data[1:]:
            node = ListNode(i)
            p.next = node

            p = p.next

        return self.head

