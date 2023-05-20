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
    
def display(head: ListNode):
    if head == None:
        print("None")
    
    else:
        p = head
        while p:
            print(p.val)
            p = p.next

class Solution:
    def reversList(self, head: ListNode) -> ListNode:
        cur = head
        pre = None
        while cur:
            temp = cur.next
            cur.next = pre

            pre = cur
            cur = temp
        return pre

if __name__ == '__main__':
    data = [1, 2, 6, 3, 4, 5, 6]
    linkList = LinkList()
    head = linkList.initList(data)
    #display(head)
    solution = Solution()
    result = solution.reversList(head)
    display(result)
