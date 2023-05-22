/* ************************************************************************
> File Name:     backtracking_sum.cpp
> Author:        xmw01
> Created Time:  Tue 25 Apr 2023 08:25:40 PM CST
> Description:   
 ************************************************************************/

/*
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]

示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<vector<int> > result;
    vector<int> path;
    // targetSum：目标和，也就是题目中的n。
    // k：题目中要求k个数的集合。
    // sum：已经收集的元素的总和，也就是path里元素的总和。
    // startIndex：下一层for循环搜索的起始位置。
    void backtracking(int targetSum, int k, int sum, int startIndex){
        if(path.size() == k){
            if(sum == targetSum) {result.push_back(path);}
            return;
        }
        for(int i = startIndex; i <=9; i++) {
            sum += i;
            path.push_back(i);
            backtracking(targetSum, k, sum, i+1);
            sum -= i;
            path.pop_back();
        }
 
    }
public:
    vector<vector<int> > combinationSum(int k, int n){
        result.clear();
        path.clear();
        backtracking(n, k, 0, 1);
        return result;
    }
};

int main() {
    Solution solution;
    vector<vector<int> > output;
    output = solution.combinationSum(3, 7); 
    cout << output.size() << endl;
    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
}