/* ************************************************************************
> File Name:     subsets.cpp
> Author:        xmw01
> Created Time:  Thu 11 May 2023 04:14:00 PM CST
> Description:   
 ************************************************************************/

/*
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例: 输入: nums = [1,2,3] 输出: [ [3],   [1],   [2],   [1,2,3],   [1,3],   [2,3],   [1,2],   [] ]
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution{
private:
    vector<vector<int> > result;
    vector<int> path;
    void backtracking(vector<int>& nums, int startIndex){
        result.push_back(path);
        if(startIndex >= nums.size()){
            return;
        }
        for(int i = startIndex; i < nums.size(); i++){
            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();
        }
    }
public:
    vector<vector<int> > subsets(vector<int>& nums){
        result.clear();
        path.clear();
        backtracking(nums, 0);
        return result;
    }
};

int main() 
{
    Solution solution;
    vector<int> nums = {1, 2, 3};
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





