/* ************************************************************************
> File Name:     4_sortedSquares.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 04:55:02 PM CST
> Description:   
 ************************************************************************/

/*
给你一个按 非递减顺序 排序的整数数组 nums，返回 每个数字的平方 组成的新数组，要求也按 非递减顺序 排序。

示例 1： 输入：nums = [-4,-1,0,3,10] 输出：[0,1,9,16,100] 解释：平方后，数组变为 [16,1,0,9,100]，排序后，数组变为 [0,1,9,16,100]

示例 2： 输入：nums = [-7,-3,2,3,11] 输出：[4,9,9,49,121]
*/


#include<iostream>
#include<vector>

using namespace std;

//this is the double pointer method
class Solution
{
public:
    vector<int> sortedSquares(vector<int>& nums){
        int left; 
        int right = nums.size() - 1;
        int index = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        for(left = 0; left <= right;){
            if(nums[left] * nums[left] > nums[right] * nums[right]){
                result[index--] = nums[left] * nums[left];
                left++;
            }else{
                result[index--] = nums[right] * nums[right];
                right--;
            }
        }
        return result;
    }
};

int main()
{
    vector<int> nums = {-4,-1,0,3,10};
    vector<int> result;
    Solution solution;

    result = solution.sortedSquares(nums);

}
