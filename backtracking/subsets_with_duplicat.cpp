/* ************************************************************************
> File Name:     subsets_with_duplicate.cpp
> Author:        xmw01
> Created Time:  Thu 11 May 2023 04:14:00 PM CST
> Description:   
 ************************************************************************/

/*
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

输入: [1,2,2]
输出: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
private:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex, vector<bool>& used){
        result.push_back(path);
        if(startIndex >= nums.size()){
            return;
        }
        for(int i = startIndex; i < nums.size(); i++){
            // used[i - 1] == true，说明同一树枝candidates[i - 1]使用过
            // used[i - 1] == false，说明同一树层candidates[i - 1]使用过
            // we're going to skip the elements that are used in the same tree layer
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false){
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            backtracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
    }
public:
    vector<vector<int> > subsets(vector<int>& nums){
        result.clear();
        path.clear();
        vector<bool> used(nums.size(), false);
        //need to be sort befor use
        sort(nums.begin(), nums.end());
        backtracking(nums, 0, used);
        return result;
    }
};

int main() 
{
    Solution solution;
    vector<int> nums = {1, 2, 2};
    vector<vector<int> > output;
    output = solution.subsets(nums); 
    cout << output.size() << endl;
    for (vector<vector<int> >::iterator iter = output.begin(); iter != output.end(); iter++){      //2D vector print
        for(vector<int>::iterator j = iter->begin(); j != iter->end(); j++){             //must use -> for pointer
            cout << *j << " ";
        }
        cout << endl;
    }
}





