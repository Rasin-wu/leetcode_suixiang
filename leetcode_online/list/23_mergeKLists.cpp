/* ************************************************************************
> File Name:     23_mergeKLists.cpp
> Author:        xmw01
> Created Time:  Mon 12 Jun 2023 04:39:35 PM CST
> Description:   
 ************************************************************************/

/*
23. 合并 K 个升序链表

给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。


输入：lists = [[1,4,5],[1,3,4],[2,6]]
输出：[1,1,2,3,4,4,5,6]
解释：链表数组如下：
[
  1->4->5,
  1->3->4,
  2->6
]
将它们合并到一个有序链表中得到。
1->1->2->3->4->4->5->6
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        if (lists.size() == 1) return lists[0];

        ListNode* preHead = new ListNode();   //保存头节点
        ListNode* tmp = preHead;
        tmp->next = lists[0];

        for (int i = 1; i < lists.size(); i++) {
            ListNode* cur = preHead->next;
            ListNode* p = preHead;
            preHead = p;   //保存本轮的头节点
            while (cur || lists[i]) {
                if (cur && lists[i]) {
                    if (cur->val < lists[i]->val) {
                        p->next = cur;
                        cur = cur->next;
                        p = p->next;
                    } else {
                        p->next = lists[i];
                        lists[i] = lists[i]->next;
                        p = p->next;
                    }
                } else if (cur) {
                    p->next = cur;
                    break;
                } else {
                    p->next = lists[i];
                    break;
                }
            }  
        }
        return preHead->next;
    }
};
