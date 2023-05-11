/* ************************************************************************
> File Name:     combined_sum.cpp
> Author:        xmw01
> Created Time:  Wed 10 May 2023 07:37:53 PM CST
> Description:   
 ************************************************************************/

/*
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。
示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为： [ [7], [2,2,3] ]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为： [ [2,2,2,2], [2,3,3], [3,5] ]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking(vector<int>& candinates, int sum, int target, int startIndex){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candinates.size(); i++){
            cout << i << " ";
            sum += candinates[i];
            path.push_back(candinates[i]);
            backtracking(candinates, sum, target, i);
            sum -= candinates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int> > combine_sum(vector<int>& candinates, int target){
        cout << target << " ";
        result.clear();
        path.clear();
        backtracking(candinates, 0, target, 0);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> candinates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int> > output;
    output = solution.combine_sum(candinates, target);
    cout << output.size() << endl;
    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
}
