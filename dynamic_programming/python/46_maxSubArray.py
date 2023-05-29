#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例: 输入: [-2,1,-3,4,-1,2,1,-5,4] 输出: 6 解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
"""
#dp[i]：包括下标i（以nums[i]为结尾）的最大连续子序列和为dp[i]。
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        if len(nums) == 0:
            return 0
        
        dp = [0] * len(nums)
        dp[0] = nums[0]
        result = 0

        for i in range(len(nums)):
            dp[i] = max(dp[i - 1] + nums[i], nums[i])
            if result < dp[i]:
                result = dp[i]
        return result

if __name__ == '__main__': 
    nums = [-2,1,-3,4,-1,2,1,-5,4]
    solution = Solution()

    result = solution.maxSubArray(nums)
    print(result)
