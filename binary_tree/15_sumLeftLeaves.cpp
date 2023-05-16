/* ************************************************************************
> File Name:     15_sumLeftLeaves.cpp
> Author:        xmw01
> Created Time:  Tue 16 May 2023 01:56:40 PM CST
> Description:   
 ************************************************************************/

/*
计算给定二叉树的所有左叶子之和。
leetcode地址:  https://leetcode.cn/problems/sum-of-left-leaves/
*/

#include<iostream>
#include<vector>
#include<queue>
#include<string>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
};

TreeNode* contructBinaryTree(vector<int>& vec)
{
    vector<TreeNode*> vecTree(vec.size(), NULL);
    TreeNode* root = NULL;
    //covert the input value array into a binary tree node array
    for(int i = 0; i < vec.size(); i++){
        TreeNode* node = NULL;
        if(vec[i] != -1) node = new TreeNode(vec[i]);
        vecTree[i] = node;
        if(i == 0) root = node;
    }

    //注意这里 结束规则是 i * 2 + 1 < vec.size()，避免空指针
    //为什么结束规则不能是i * 2 + 2 < arr.length呢?
    //如果i * 2 + 2 < arr.length 是结束条件
    //那么i * 2 + 1这个符合条件的节点就被忽略掉了
    for(int i = 0; i * 2 + 1 < vec.size(); i++){
        if(vecTree[i] != NULL){
            //线性存储转链式存储的关键
            vecTree[i]->left = vecTree[i * 2 + 1];
            if((i * 2 + 2) < vec.size()){
                vecTree[i]->right = vecTree[i * 2 + 2];
            }
        }
    }
    return root;
}


class Solution {
public:
    int result;
    
    int getSumLeftLeaves(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 0;

        int leftSum = getSumLeftLeaves(root->left);     //左
        if(root->left && root->left->left == NULL && root->left->right == NULL) {
            leftSum = root->left->val;
        }
        int rightSum = getSumLeftLeaves(root->right);  //右

        result = leftSum + rightSum;    // 中
        return result;
    }

};


int main()
{
    vector<int> treeInput = {4,2,7,1,3,6,9};
    int output;
    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    output = solution.getSumLeftLeaves(root);

    cout << output << endl;
    return 0;
}

