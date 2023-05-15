/* ************************************************************************
> File Name:     9_maxdepth.cpp
> Author:        xmw01
> Created Time:  Mon 15 May 2023 03:47:08 PM CST
> Description:   
 ************************************************************************/

/*
给定一个二叉树，找出其最大深度。

二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。

说明: 叶子节点是指没有子节点的节点。

示例： 给定二叉树 [3,9,20,null,null,15,7]，

返回它的最大深度3
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


class Solution_1 {
public:
    //本题可以使用前序（中左右），也可以使用后序遍历（左右中），使用前序求的就是深度，使用后序求的是高度。
    //以下是后序的迭代法
    int depth(TreeNode* root) {
        if(root == NULL) return 0;
        int cnt_left = depth(root->left);          //左
        int cnt_right = depth(root->right);        //右
        int result = 1 + max(cnt_left, cnt_right); //中
        return result;
    }
    int maxdepth(TreeNode* root) {
        int cnt;
        cnt = depth(root);
        return cnt;
    }
};

class Solution {
public:
    int result = 0;
    //本次使用前序的方法，这个是回溯的精髓所在
    void getdepth(TreeNode* root, int depth) {   
        result = result > depth ? result : depth;    //中

        if(root->left == NULL && root->right == NULL) return;
        
        if(root->left){     //左
            depth++;
            getdepth(root->left, depth);
            depth--;
        }

        if(root->right){    //右
            depth++;
            getdepth(root->right, depth);
            depth--;
        }

        return;

    }
    int maxdepth(TreeNode* root) {
        if(root == NULL) {
            return result;
        }
        getdepth(root, 1);
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
    int result = solution.maxdepth(root);

    cout << result << endl;
    
    return 0;
}






