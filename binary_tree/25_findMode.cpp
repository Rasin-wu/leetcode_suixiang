/* ************************************************************************
> File Name:     25_findMode.cpp
> Author:        xmw01
> Created Time:  Thu 18 May 2023 11:24:55 AM CST
> Description:   
 ************************************************************************/

/*
给定一个有相同值的二叉搜索树（BST），找出 BST 中的所有众数（出现频率最高的元素）。
*/


#include<iostream>
#include<vector>
#include<queue>
#include<string>
#include<algorithm>
#include<unordered_map>

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
    unordered_map<int, int> map_num;
    vector<int> result = {};
    void searchBST(TreeNode* root) {
        if (root == NULL) return;
        searchBST(root->left);
        map_num[root->val]++;
        searchBST(root->right);
    }
    static bool cmp(pair<int, int> pair1, pair<int, int> pair2) {
        return pair1.second > pair2.second;
    }

    vector<int> findMode(TreeNode* root) {
        map_num.clear();
        result.clear();
        searchBST(root);
        vector<pair<int, int>> vec_pair(map_num.begin(), map_num.end());
        result.push_back(vec_pair[0].first);
        sort(vec_pair.begin(), vec_pair.end(), cmp);
        for (int i = 1; i < vec_pair.size(); i++) {
            if (vec_pair[i].second == vec_pair[i - 1].second) {
                result.push_back(vec_pair[i].first);
            }
        }
        return result;

    }
     

};


int main()
{
    vector<int> treeInput = {3,3,2,1,6,0,5};
    vector<int> output = {};
    //TreeNode* output;

    TreeNode* root = NULL;
    root = contructBinaryTree(treeInput);

    Solution solution;
    Display display;
    output = solution.findMode(root);

    for (int i : output) {
        cout << i << endl;
    }
    //output = display.levelOrder(root);

    /*
    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
    */
    return 0;
}

