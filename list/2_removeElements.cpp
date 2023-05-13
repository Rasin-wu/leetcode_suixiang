/* ************************************************************************
> File Name:     2_removeElements.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 06:14:14 PM CST
> Description:   
 ************************************************************************/

/*
题意：删除链表中等于给定值 val 的所有节点。

示例 1： 输入：head = [1,2,6,3,4,5,6], val = 6 输出：[1,2,3,4,5]

示例 2： 输入：head = [], val = 1 输出：[]

示例 3： 输入：head = [7,7,7,7], val = 7 输出：[]
*/


#include<iostream>
#include<vector>

using namespace std;

struct ListNode 
{
    int val;  //elements stored on nodes
    ListNode *next;  //pointer to the next nodes
    ListNode(): val(0), next(NULL) {}  //节点的构造函数
    ListNode(int x): val(x), next(NULL) {}
};

void display(ListNode *L){

    while (L){
        cout << L->val << " ";
        L = L->next;
    }
    cout << endl;
}

class Solution
{
public:
    ListNode* removeElements(ListNode* head, int val){
        //delete the header node
        while(head != NULL && head->val == val) {
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        //delete other node that not header
        ListNode* cur = head;
        while(cur != NULL && cur->next != NULL){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
    
    return head;
    }
};



int main()
{
    vector<int> list = {1,6,6,6,6,2,3,4,5,6};
    ListNode* head = new ListNode();
    ListNode* p = head;
    int len = list.size();
    int val = 6;
    for(int i = 0; i < len; i++){
        ListNode* q = new ListNode();
        q->val = list[i];
        q->next = nullptr;
        p->next = q;
        p = p->next;
    }
    Solution solution;
    solution.removeElements(head, val);

    display(head);
    return 0;
    
}
