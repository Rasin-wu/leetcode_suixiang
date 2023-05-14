/* ************************************************************************
> File Name:     1_binary_tree.cpp
> Author:        xmw01
> Created Time:  Sun 14 May 2023 05:46:33 PM CST
> Description:   
 ************************************************************************/


struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x): val(x), left(NULL), right(NULL) {}
}


// recursive traversal
// 递归遍历

// 前序遍历
class Solution
{
public:
    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur == NULL) return;
        vec.push_back(cur->val);   //中
        traversal(cur->left, vec); //左
        traversal(cur->right, vec);//右
    }
    vector<int> perorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 中序遍历
class Solution
{
public:
    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur == NULL) return;
        traversal(cur->left, vec);  //左
        vec.push_back(cur->val);    //中
        traversal(cur->right, vec); //右
    }
    vector<int> midorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};

// 后序遍历
class Solution
{
public:
    void traversal(TreeNode* cur, vector<int>& vec){
        if(cur == NULL) return;
        traversal(cur->left, vec);  //左
        traversal(cur->right, vec); //右
        vec.push_back(cur->val);    //中
    }
    vector<int> postorderTraversal(TreeNode* root){
        vector<int> result;
        traversal(root, result);
        return result;
    }
};








