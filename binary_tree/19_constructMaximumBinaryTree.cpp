/* ************************************************************************
> File Name:     19_constructMaximumBinaryTree.cpp
> Author:        xmw01
> Created Time:  Wed 17 May 2023 11:51:33 AM CST
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
    // 构造树一般采用的是前序遍历，因为先构造中间节点，然后递归构造左子树和右子树。
    TreeNode* traveral(vector<int>& nums) {
        TreeNode* node = new TreeNode(0);
        //cut-off condition
        if(nums.size() == 1) {
            node->val = nums[0];
            return node;
        }
        int maxIndex  = 0;
        int maxValue  = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(maxValue < nums[i]) {
                maxValue = nums[i];
                maxIndex = i;
                cout << maxValue << endl;
            }
        }
        node->val = maxValue;
        //construct the left subtree, the left interval of the maximum value 
        if(maxIndex > 0) {
            vector<int> vector_left(nums.begin(), nums.begin() + maxIndex);
            node->left = traveral(vector_left);
        }

        //construct the right subtree, the right interval of the maximum value 
        if(maxIndex < nums.size()) {
            vector<int> vector_right(nums.begin() + maxIndex + 1, nums.end());
            node->right = traveral(vector_right);
        }

        return node;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        return traveral(nums);
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
    root = solution.constructMaximumBinaryTree(treeInput);

    output = display.levelOrder(root);

    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}

