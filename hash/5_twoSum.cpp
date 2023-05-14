/* ************************************************************************
> File Name:     5_twoSum.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 10:39:37 PM CST
> Description:   
 ************************************************************************/

/*
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]]]]]
*/

#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target){
        unordered_map<int, int> map;
        for(int i = 0; i < nums.size(); i++){
            
            //
            auto iter = map.find(target - nums[i]);
            if(iter != map.end()){
                return {iter->second, i};
            }
            map.insert(pair<int ,int>(nums[i], i));
            
        }
        return {};
    }
};

int main()
{
    vector<int> result;
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    Solution solution;
    result = solution.twoSum(nums, target);
    cout << result[0] << " " << result[1] << endl;
}






