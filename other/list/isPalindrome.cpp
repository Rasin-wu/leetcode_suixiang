/* ************************************************************************
> File Name:     isPalindrome.cpp
> Author:        xmw01
> Created Time:  Mon 12 Jun 2023 10:34:31 AM CST
> Description:   
 ************************************************************************/

#include <iostream>
#include <vector>

using namespace std;

//单链表
struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(NULL) {}  //节点的构造函数
    ListNode(int x): val(x), next(NULL) {}  //节点的构造函数
    ListNode(int x, ListNode* next): val(x), next(next) {}  //节点的构造函数
};

void display(ListNode *L){
    while (L){
        cout << L->val << " ";
        L = L->next;
    }
    cout << endl;
}

class Solution {
public:
    bool isPalindrome(ListNode* head){
        vector<int> vec;
        ListNode* cur = head;
        while(cur) {
            if(cur) {
                vec.push_back(cur->val);
            }
            cur = cur->next;
        }
        for (int i = 0, j = vec.size() - 1; i < vec.size(), j >= 0; i++, j--){
            if (vec[i] != vec[j]) {
                return false;
            }
        }
        return true;
    }
};

int main() {
    vector<int> list = {1,2,3,4,3,2,1};
    ListNode* head = new ListNode();
    head->val = 1;
    ListNode* p = head;
    int len = list.size();
    int val;
    for (int i = 1; i < len; i++) {
        ListNode* q = new ListNode();
        q->val = list[i];
        q->next = nullptr;
        p->next = q;
        p = p->next;
    }
    Solution solution;
    bool result = solution.isPalindrome(head);
    cout << result << endl;
}