/* ************************************************************************
> File Name:     17_hasPathSum.cpp
> Author:        xmw01
> Created Time:  Tue 16 May 2023 11:11:25 PM CST
> Description:   
 ************************************************************************/


/*
给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。

说明: 叶子节点是指没有子节点的节点。

示例: 给定如下二叉树，以及目标和 sum = 22，
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
    bool traveral(TreeNode* root, int count) {
        if(root->left == NULL && root->right == NULL && count == 0) return true;
        if(root->left == NULL && root->right == NULL) return false;

        if(root->left) {    //左
            count -= root->left->val;   //递归
            if(traveral(root->left, count)) return true;
            count += root->left->val;     //回溯
        }
        if(root->right) {   //右
            count -= root->right->val;  //递归
            if(traveral(root->right, count)) return true;
            count += root->right->val;     //回溯
        }

        return false;

    }

    bool hasPathSum(TreeNode* root, int sum) {
        if(root == NULL) return false;
        return traveral(root, sum - root->val);
    }
};


int main()
{
    vector<int> treeInput = {4,2,7,1,3,6,9};
    bool output;
    int sum = 20;

    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    output = solution.hasPathSum(root, sum);

    cout << output << endl;
    return 0;
}

