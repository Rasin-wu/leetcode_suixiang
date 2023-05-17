/* ************************************************************************
> File Name:     23_getMinimumDiff.cpp
> Author:        xmw01
> Created Time:  Wed 17 May 2023 10:47:08 PM CST
> Description:   
 ************************************************************************/

/*
给你一棵所有节点为非负值的二叉搜索树，请你计算树中任意两节点的差的绝对值的最小值。
*/

/*
那么二叉搜索树采用中序遍历，其实就是一个有序数组。

在一个有序数组上求两个数最小差值
*/


#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<climits>

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
    //那么二叉搜索树采用中序遍历，其实就是一个有序数组, 在一个有序数组上求两个数最小差值
    vector<int> vec_tree = {};
    void traversal(TreeNode* root) {
        if (root == NULL) return;
        traversal(root->left);  //左
        vec_tree.push_back(root->val);  //中
        traversal(root->right);     //右
    }

    int getMinimumDiff(TreeNode* root) {
       traversal(root);
       int min_abs = INT32_MAX;
       for (int i = 1; i < vec_tree.size(); i++) {
            if (min_abs > abs(vec_tree[i] - vec_tree[i-1])) {
                min_abs = abs(vec_tree[i] - vec_tree[i-1]);
            }
       }
       return min_abs;
    }

};


int main()
{
    vector<int> treeInput = {3,2,1,6,0,5};
    //TreeNode* output;

    int result;

    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    Display display;
    result = solution.getMinimumDiff(root);
    cout << result << endl;


    return 0;
}

