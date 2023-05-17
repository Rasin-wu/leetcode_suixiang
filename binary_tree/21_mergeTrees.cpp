/* ************************************************************************
> File Name:     21_mergeTrees.cpp
> Author:        xmw01
> Created Time:  Wed 17 May 2023 03:22:51 PM CST
> Description:   
 ************************************************************************/

/*
给定两个二叉树，想象当你将它们中的一个覆盖到另一个上时，两个二叉树的一些节点便会重叠。

你需要将他们合并为一个新的二叉树。合并的规则是如果两个节点重叠，那么将他们的值相加作为节点合并后的新值，否则不为 NULL 的节点将直接作为新二叉树的节点。
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
    TreeNode* mergeTrees(TreeNode* tree1, TreeNode* tree2) {
        if(tree1 == NULL) return tree2;
        if(tree2 == NULL) return tree1;
        
        tree1->val += tree2->val;    //中
        tree1->left = mergeTrees(tree1->left, tree2->left);   //左
        tree1->right = mergeTrees(tree1->right, tree2->right);  //右
        
        return tree1;
    }
};


int main()
{
    vector<int> vector_tree1 = {1,3,2,5};
    vector<int> vector_tree2 = {2,1,3,-1,4,-1,7};

    vector<vector<int>> output = {};
    //TreeNode* output;

    TreeNode* tree1 = NULL;
    TreeNode* tree2 = NULL;
    TreeNode* root = NULL;
    tree1 = contructBinaryTree(vector_tree1);
    tree2 = contructBinaryTree(vector_tree2);

    Solution solution;
    Display display;
    root = solution.mergeTrees(tree1, tree2);

    output = display.levelOrder(root);

    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
    return 0;
}

