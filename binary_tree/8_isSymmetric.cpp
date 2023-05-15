/* ************************************************************************
> File Name:     8_isSymmetric.cpp
> Author:        xmw01
> Created Time:  Mon 15 May 2023 02:35:33 PM CST
> Description:   
 ************************************************************************/

/*
给定一个二叉树，检查它是否是镜像对称的。

*/

#include<iostream>
#include<vector>
#include<queue>

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
    bool compare(TreeNode* left, TreeNode* right) {

        //The empty node case is ruled out first
        if(left != NULL && right == NULL) return false;
        else if(left == NULL && right != NULL) return false;
        else if(left == NULL && right == NULL) return true;
        else if(left->val != right->val) return false;

        // 此时，左右节点都不为空，且数值相同
        // 接下来才做递归， 做下一层的判断
        bool outside = compare(left->right, right->left);
        bool inside = compare(left->left, right->right);
        bool result = outside && inside;
        return result;
    }
    bool isSymmetric(TreeNode* root) {
        if (root == NULL) return true;
        bool result = compare(root->left, root->right);
        return result;
        
    }
};


int main()
{
    vector<int> treeInput = {1, 2, 2, 3, 4, 4, 3, 0};
    //vector<int> treeInput = {1, 2, 2, 3, 4, 4, 3};
    vector<vector<int>> output;
    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    bool result;
    result = solution.isSymmetric(root);

    cout << result << endl;

    return 0;
}



