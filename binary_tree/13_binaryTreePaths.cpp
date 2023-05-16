/* ************************************************************************
> File Name:     13_binaryTreePaths.cpp
> Author:        xmw01
> Created Time:  Tue 16 May 2023 09:42:29 AM CST
> Description:   
 ************************************************************************/


/*
 给定一个二叉树，返回所有从根节点到叶子节点的路径。

 说明: 叶子节点是指没有子节点的节点。
leetcode: https://leetcode.cn/problems/binary-tree-paths/
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
    vector<string> result;
    vector<int> path = {};

    void getpath(TreeNode* root, vector<int>& path, vector<string>& result) {
        path.push_back(root->val); //中，中为什么写在这里，因为最后一个节点也要加入到path中
        if(root->left == NULL && root->right == NULL){
            string str_tmp = "";
            for(int i = 0; i < path.size() - 1; i++){
                str_tmp += to_string(path[i]);
                str_tmp += "->";
            }
            str_tmp += to_string(path[path.size() - 1]);
            result.push_back(str_tmp);
            return;      //此处必须要返回，这个是递归的截至条件
        }

        if(root->left) {  //左
            getpath(root->left, path, result);
            path.pop_back();  //需要回溯
        }

        if(root->right) {   //右
            getpath(root->right, path, result);
            path.pop_back();   //需要回溯
        }
        
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        if(root == NULL) return result;
        getpath(root, path, result);
        return result;
    }
};


int main()
{
    vector<int> treeInput = {4,2,7,1,3,6,9};
    vector<string> output;
    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    output = solution.binaryTreePaths(root);

    for(vector<string>::iterator iter = output.begin(); iter != output.end(); iter++) {             //must use -> for pointer
        cout << *iter << endl;
    }
    return 0;
}

