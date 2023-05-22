/* ************************************************************************
> File Name:     backtracking.cpp
> Author:        xmw01
> Created Time:  Mon 24 Apr 2023 07:17:33 PM CST
> Description:   
 ************************************************************************/

/*
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4], ]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking(int n, int k, int startIndex){
        if (path.size() ==k){
            result.push_back(path);
            return;
        } 
        for(int i = startIndex; i <=n; i++){
            path.push_back(i);
            backtracking(n, k, i+1);
            path.pop_back();
        }
    }
    /*  Here is the template for the bracking algorithm
    void backtracking(参数) {
    if (终止条件) {
        存放结果;
        return;
    }

    for (选择：本层集合中元素（树中节点孩子的数量就是集合的大小）) {
        处理节点;
        backtracking(路径，选择列表); // 递归
        回溯，撤销处理结果
    }
}
    */
public:
    vector<vector<int> > combine(int n, int k){
        result.clear();
        path.clear();
        backtracking(n, k, 1);
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > output; 
    output = solution.combine(4, 2); 
    cout << output.size() << endl;
    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
}