/* ************************************************************************
> File Name:     canPartition.cpp
> Author:        xmw01
> Created Time:  Sat 13 May 2023 11:48:18 AM CST
> Description:   
 ************************************************************************/

/*
题目难易：中等

给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

注意: 每个数组中的元素不会超过 100 数组的大小不会超过 200

示例 1:

输入: [1, 5, 11, 5]
输出: true
解释: 数组可以分割成 [1, 5, 5] 和 [11].
示例 2:

输入: [1, 2, 3, 5]
输出: false
解释: 数组不能分割成两个元素和相等的子集.
提示：

1 <= nums.length <= 200
1 <= nums[i] <= 100
*/

#include<iostream>
#include<vector>

using namespace std;

class Solution
{
public:
    bool canPartition(vector<int>& nums){

        if(nums.size() == 1) return false;
        int sum = 0;

        // dp[i]中的i表示背包内总和
        // 总和不会大于20000，背包最大只需要其中一半，所以10001大小就可以了
        for(int item : nums){
            sum += item;
        }

        /// int sum = accumulate(nums.begin(), nums.end(), 0);
        if((sum % 2) == 1) return false;
        int target = sum/2;

        vector<int> dp(10001, 0);

        for(int i = 0; i < nums.size(); i++){
            for(int j = target; j >= nums[i]; j--){
                dp[j] = max(dp[j], dp[j - nums[i]]+ nums[i]); // each element must be non repeatable, so traverse from large to small
            }
        }
        if(dp[target] == target){
            return true;
        }else return false;
        
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {1, 5, 11, 5};
    bool result = solution.canPartition(nums);
    cout << "The answer is: " << result << endl;
}









