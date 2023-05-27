#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
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
    1 <= nums[i] <= 100]
"""

class Solution:
    def canPartition(self, nums: List[int]) -> bool:
        target = sum(nums)
        if target % 2 == 1:
            return False

        #target = target // 2
        target = target // 2

        dp = [0] * (target + 1)

        for i in range(len(nums)):
            for j in range(target, nums[i] - 1, -1):
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i])

        return target == dp[target]


if __name__ == '__main__':
    nums = [1, 5, 11, 5]

    solution = Solution()
    result = solution.canPartition(nums)
    print(result)
