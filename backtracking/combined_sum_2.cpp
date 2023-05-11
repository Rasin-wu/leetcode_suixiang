/* ************************************************************************
> File Name:     combined_sum.cpp
> Author:        xmw01
> Created Time:  Wed 10 May 2023 07:37:53 PM CST
> Description:   
 ************************************************************************/

/*
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明： 所有数字（包括目标数）都是正整数。解集不能包含重复的组合。

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
所求解集为:
[
[1, 7],
[1, 2, 5],
[2, 6],
[1, 1, 6]
]
示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
所求解集为:
[
[1,2,2],
[5]
]
*/

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

class Solution{
private:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking(vector<int>& candinates, int sum, int target, int startIndex, vector<bool>& used){
        if(sum > target){
            return;
        }
        if(sum == target){
            result.push_back(path);
            return;
        }
        for (int i = startIndex; i < candinates.size() && (sum + candinates[i]) <= target; i++){
            // to skip elements that have been used in the same tree layer
            if(i > 0 && candinates[i] == candinates[i-1] && used[i-1] == false){
                continue;
            }
            used[i] = true;
            sum += candinates[i];
            path.push_back(candinates[i]);
            // 这里必须要用i+1 不能用 i++ 切记   因为在这里面的数字是不可以重复利用的，所以用i+1
            backtracking(candinates, sum, target, i + 1, used);
            used[i] = false;
            sum -= candinates[i];
            path.pop_back();
        }
    }
public:
    vector<vector<int> > combine_sum_2(vector<int>& candinates, int target){
        result.clear();
        path.clear();
        vector<bool> used(candinates.size(), false);
        // sort the candinates so that their identical elements are all placed next to each other
        sort(candinates.begin(), candinates.end());
        backtracking(candinates, 0, target, 0, used);
        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> candinates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    vector<vector<int> > output;
    output = solution.combine_sum_2(candinates, target);
    cout << output.size() << endl;
    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
}
