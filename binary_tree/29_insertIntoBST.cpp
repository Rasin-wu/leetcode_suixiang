/* ************************************************************************
> File Name:     29_insertIntoBST.cpp
> Author:        xmw01
> Created Time:  Thu 18 May 2023 08:20:04 PM CST
> Description:   
 ************************************************************************/

/*
给定二叉搜索树（BST）的根节点和要插入树中的值，将值插入二叉搜索树。 返回插入后二叉搜索树的根节点。 输入数据保证，新值和原始二叉搜索树中的任意节点值都不同。

注意，可能存在多种有效的插入方式，只要树在插入后仍保持为二叉搜索树即可。 你可以返回任意有效的结果。
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

class Display 
{
public:
    vector<vector<int>> levelOrder(TreeNode* root){
        queue<TreeNode*> que;
        if(root!= NULL) que.push(root);

        vector<vector<int>> result;
        while(!que.empty()){
            int size = que.size();
            vector<int> vec;
            //这里一定要使用固定大小size，不要使用que.size()，因为que.size是不断变化的)
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                vec.push_back(node->val);
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);

            }
            result.push_back(vec);
        }
        return result;
    }
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL) {
            TreeNode* node = new TreeNode(val);
            return node;
        }
        if(root->val > val) root->left = insertIntoBST(root->left, val);
        if(root->val < val) root->right = insertIntoBST(root->right, val);

        return root;
    }

};


int main()
{
    vector<int> treeInput = {3,2,1,6,0,5};
    vector<vector<int>> output = {};
    //TreeNode* output;

    TreeNode* root = NULL;
    //root = contructBinaryTree(treeInput);

    Solution solution;
    Display display;
    return 0;
}

