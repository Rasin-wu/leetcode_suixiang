/* ************************************************************************
> File Name:     myList.cpp
> Author:        xmw01
> Created Time:  Thu 13 Oct 2022 07:29:58 PM CST
> Description:   
 ************************************************************************/
#include <iostream>
using namespace std;

class MyLinkedList {
public:
    struct LinkedNode{
        int val;
        LinkedNode* next;
        LinkedNode(int val):val(val), next(nullptr){};
    }

    //初始化链表
    MyLinkedList(){
        _dummyHead = new LinkedNode(0);
        _size = 0;
    }

    //获取到第index个节点的数值，如果index是非法数值直接返回-1
    int get(int index) {
        if(index > (_seze - 1) || index < 0) {
            return -1;
        }
        LinkedNode* cur = _dummyHead->next;
        while(index--){
            cur = cur->next;
        }
        return cur->val;
    }

    //在链表最前面插入一个节点
    void addAtHead(int val){
        LinkedNode* newNode = new LinkedNode(val);
        newNode->next = _dummyHead->next;
        _dummyHead->next = newNode;
        _size++;
    }

    //在链表的最后添加一个节点
    void addAtTail(int val){
        LinkedNode* newNode = new LinkedNode(val);
        LinkedNode* cur = _dummyHead;

    }


}
