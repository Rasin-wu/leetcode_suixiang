/* ************************************************************************
> File Name:     24_swapPairs.cpp
> Author:        xmw01
> Created Time:  Mon 12 Jun 2023 05:14:54 PM CST
> Description:   
 ************************************************************************/

/*
给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。

输入：head = [1,2,3,4]
输出：[2,1,4,3]
*/

//暴力强行遍历

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
    ListNode* swapPairs(ListNode* head) {
        ListNode* preHead = new ListNode();
        ListNode* cur = preHead;
        while (head) {
            if (head->next) {
                ListNode* tmp1 = new ListNode(head->next->val);  //不要想着复用head, 地址的复制会使得这个链表陷入循环
                cur->next = tmp1;
                cur = cur->next;
                ListNode* tmp2 = new ListNode(head->val);
                cur->next = tmp2;
                cur = cur->next;
                head = head->next->next;
            } else {
                cur->next = head;
                head = head->next;
                cur = cur->next;
            }
        }
        return preHead->next;
    }
};

//下面这个也是迭代法：
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* preHead = new ListNode();
        preHead->next = head;
        ListNode* cur = preHead;
        preHead->next = head;
        while (cur->next && cur->next->next) {
            ListNode* node1 = cur->next; 
            ListNode* node2 = cur->next->next;
            cur->next = node2;
            node1->next = node2->next;
            node2->next = node1;
            
            cur = node1;
            }
        return preHead->next;
    }
};