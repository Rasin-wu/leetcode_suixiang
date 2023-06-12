/* ************************************************************************
> File Name:     2_addTwoNumbers.cpp
> Author:        xmw01
> Created Time:  Mon 12 Jun 2023 03:35:36 PM CST
> Description:   
 ************************************************************************/

/*
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        ListNode* preHead = new ListNode();
        ListNode* p = preHead;

        int ten = 0;
        while (l1 != nullptr && l2 != nullptr) {
            ListNode* cur = new ListNode();
            if ((l1->val + l2->val + ten) > 9) {
                cur->val = (l1->val + l2->val + ten) % 10;
                ten = 1;
            } else {
                cur->val = l1->val + l2->val + ten;
                ten = 0;
            }
            l1 = l1->next;
            l2 = l2->next;
            p->next = cur;
            p = p->next;
        }
        ListNode* other = l1 ? l1 : l2;
        while (other) {
            ListNode* cur = new ListNode();
            if ((other->val + ten) > 9) {
                cur->val = (other->val + ten) % 10;
                ten = 1;
            } else {
                cur-> val = other->val + ten;
                ten = 0;
            }
            other = other->next;
            p->next = cur;
            p = p->next;
        }
        if (ten == 1) { 
            ListNode* cur = new ListNode(1);
            p->next = cur;
        }

        return preHead->next;
    }
};
