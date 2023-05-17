/* ************************************************************************
> File Name:     23_isValidBST.cpp
> Author:        xmw01
> Created Time:  Wed 17 May 2023 09:59:48 PM CST
> Description:   
 ************************************************************************/

/*
给定一个二叉树，判断其是否是一个有效的二叉搜索树。

假设一个二叉搜索树具有如下特征：

节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
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
    
    long long maxValue = LONG_MIN;   // 因为后台测试数据中有int最小值

    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;
        bool left = isValidBST(root->left);     //左

        //中序遍历，验证遍历的元素是不是从小到大
        if (maxValue < root->val) maxValue = root->val;    //中
        else return false;
        bool right = isValidBST(root->right);     //右

        return left && right;

    }

};


int main()
{
    vector<int> treeInput = {3,2,1,6,0,5};
    //TreeNode* output;

    bool result;
    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    Display display;
    result = solution.isValidBST(root);
    cout << result << endl;


    return 0;
}

