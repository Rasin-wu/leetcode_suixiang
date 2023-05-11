/* ************************************************************************
> File Name:     list.cpp
> Author:        xmw01
> Created Time:  Tue 11 Oct 2022 08:20:49 PM CST
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

//*****************************************************************************
//*****************************************************************************

//题目：移除链表元素   https://leetcode.cn/problems/remove-linked-list-elements/
//方案一：使用原来链表进行节点删除
class remove_Solution_a{
public:
    ListNode* removeElements(ListNode* head, int val){
        //删除头节点
        while(head != NULL && head->val == val){
            ListNode* tmp = head;
            head = head->next;
            delete tmp;
        }
        //删除非头节点
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

//方案二； 设置一个虚拟头节点再进行移除节点操作
class remove_Solution_b{
public:
    ListNode* removeElements(ListNode* head, int val){
        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;
        ListNode* cur = dummyHead;
        while(cur->next != NULL){
            if(cur->next->val == val){
                ListNode* tmp = cur->next;
                cur->next = cur->next->next;
                delete tmp;
            }else{
                cur = cur->next;
            }
        }
        head = dummyHead->next;
        delete dummyHead;
        return head;
    }
};


//*****************************************************************************
//*****************************************************************************

//题目： 反转列表  https://leetcode.cn/problems/reverse-linked-list/
//方法一：双指针法

class reverseSolution_a{
public:
    ListNode* reverseList(ListNode* head){
        ListNode* temp;
        ListNode* cur = head;
        ListNode* pre = NULL;
        while(cur){
            temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;

    }
}

//方法二：递归法

class reverseSolution_b{
public:
    ListNode* reverse(ListNode* pre, ListNode* cur){
        if(cur == NULL) return pre;
        ListNode* temp = cur->next;
        cur->next = pre;
    }
}

int main() {
    vector<int> list = {1, 2, 6, 3, 4, 5, 6};
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
