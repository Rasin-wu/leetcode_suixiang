/* ************************************************************************
> File Name:     143_reorderList.cpp
> Author:        xmw01
> Created Time:  Mon 12 Jun 2023 01:39:54 PM CST
> Description:   
 ************************************************************************/

/*
给定一个单链表 L 的头节点 head ，单链表 L 表示为：

L0 → L1 → … → Ln - 1 → Ln
请将其重新排列后变为：

L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

 

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/reorder-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
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
    void reorderList(ListNode* head) {
        if (!head) return;
        ListNode* cur = head;
        vector<ListNode*> vec_list;
        while (cur) {
            vec_list.push_back(cur);
            cur = cur->next;
        }
        int i = 0;
        int j = vec_list.size() - 1;
        while (i < j) {
            vec_list[i]->next = vec_list[j];
            //i++;
            vec_list[j--]->next = vec_list[++i];
            //j--;
        }
        vec_list[i]->next = nullptr;
    }
};
