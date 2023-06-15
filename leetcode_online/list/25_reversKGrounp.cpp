/* ************************************************************************
> File Name:     25_reversKGrounp.cpp
> Author:        xmw01
> Created Time:  Thu 15 Jun 2023 07:41:46 PM CST
> Description:   
 ************************************************************************/

/*
给你链表的头节点 head ，每 k 个节点一组进行翻转，请你返回修改后的链表。

k 是一个正整数，它的值小于或等于链表的长度。如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。

你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。

输入：head = [1,2,3,4,5], k = 2
输出：[2,1,4,3,5]

输入：head = [1,2,3,4,5], k = 3
输出：[3,2,1,4,5]

https://leetcode.cn/problems/reverse-nodes-in-k-group/
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

//做的方法有点绕，可以画图好好理解一下。
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head) return nullptr;
        ListNode* preHead = new ListNode(0);
        ListNode* pre = preHead;
        ListNode* cur = head;
        preHead->next = head;
        int num = 0, iter = 1;
        while (head) {
            num++;
            head = head->next;
        }
        while (iter * k <= num){
            for(int i = 0; i < k - 1; i++){
                ListNode* next = cur->next;
                cur->next = next->next;
                next->next =  pre->next;
                pre->next = next; 
            }
            iter++;
            pre = cur;
            cur = pre->next;
        }
        return preHead->next;
    }
};