/* ************************************************************************
> File Name:     16_findBottomLeftValue.cpp
> Author:        xmw01
> Created Time:  Tue 16 May 2023 05:30:23 PM CST
> Description:   
 ************************************************************************/

/*
给定一个二叉树，在树的最后一行找到最左边的值。
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
    int maxDepth = INT32_MIN;
    int result;

    void bottomLeftValueTraversal(TreeNode* root, int depth) {
        //if(root == NULL) return;    
        if(root->left == NULL && root->right == NULL) {
            if(depth > maxDepth) {
                maxDepth = depth;
                result = root->val;
            }
            return;  // 中  这个必须在花括号以外
        }
        if(root->left) {     //左
            depth++;
            bottomLeftValueTraversal(root->left, depth);
            depth--;      //回溯
        }
        if(root->right) {    //右
            depth++;
            bottomLeftValueTraversal(root->right, depth);
            depth--;   //回溯
        }
        return;
    }

    int findBottomLeftValue(TreeNode* root) {
        bottomLeftValueTraversal(root, 0); 
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
    output = solution.findBottomLeftValue(root);

    cout << output << endl;
    return 0;
}

