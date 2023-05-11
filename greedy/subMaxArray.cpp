/* ************************************************************************
> File Name:     subMaxArray.cpp
> Author:        xmw01
> Created Time:  Thu 11 May 2023 08:16:04 PM CST
> Description:   
 ************************************************************************/

/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
*/

#include<iostream>
#include<vector>
using namespace std;

//violent Solution
class Solution_1
{
public:
    int maxSubArray(vector<int> nums){
        int max_sum = INT32_MIN;
        for(int i = 0; i < nums.size(); i++){
            int tmp_sum = 0;
            for(int j = i; j < nums.size(); j++){
                tmp_sum += nums[j];
                max_sum = tmp_sum > max_sum ? tmp_sum : max_sum;
            }
        }
        return max_sum;
    }
};

//greedy solution
class Solution
{
public:
    int maxSubArray(vector<int> nums){
        int max_sum = INT32_MIN;
        int tmp_sum = 0;
        for(int i =0; i < nums.size(); i++){
           tmp_sum += nums[i];
           if(tmp_sum > max_sum){
               max_sum = tmp_sum;
           }
           if(tmp_sum < 0) tmp_sum = 0;
        }
        return max_sum;
    }
};

int main()
{
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int result;
    Solution solution;

    result = solution.maxSubArray(nums);
    cout << "The answer is: " << result << endl;
}
