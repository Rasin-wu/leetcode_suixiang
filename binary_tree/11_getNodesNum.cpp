/* ************************************************************************
> File Name:     11_getNodesNum.cpp
> Author:        xmw01
> Created Time:  Mon 15 May 2023 09:57:44 PM CST
> Description:   
 ************************************************************************/

/*
给出一个完全二叉树，求出该树的节点个数。

示例 1：

输入：root = [1,2,3,4,5,6]
输出：6
示例 2：

输入：root = []
输出：0
示例 3：

输入：root = [1]
输出：1
提示：

树中节点的数目范围是[0, 5 * 10^4]
0 <= Node.val <= 5 * 10^4
题目数据保证输入的树是 完全二叉树
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

//这道题目的递归法和求二叉树的深度写法类似
class Solution {
public:

    int getNodesNum(TreeNode* root) {
        if(root == NULL) return 0;
        int leftNodesNum = getNodesNum(root->left);     //左
        int rightNodesNum = getNodesNum(root->right);   //右
        int result = leftNodesNum + rightNodesNum + 1;  //中
        return result;
    }

};

int main()
{
    vector<int> treeInput = {4,2,7,1,3,6,9};
    vector<vector<int>> output;
    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    int result = solution.getNodesNum(root);

    cout << "The answer is: " << result << endl;

    return 0;
}

