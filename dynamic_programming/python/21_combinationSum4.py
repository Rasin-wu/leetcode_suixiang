#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个由正整数组成且不存在重复数字的数组，找出和为给定目标正整数的组合的个数。

示例:

    nums = [1, 2, 3]
    target = 4
    所有可能的组合为： (1, 1, 1, 1) (1, 1, 2) (1, 2, 1) (1, 3) (2, 1, 1) (2, 2) (3, 1)
    
    请注意，顺序不同的序列被视作不同的组合。
    
    因此输出为 7。
"""

"""
如果求组合数就是外层for循环遍历物品，内层for遍历背包。

如果求排列数就是外层for遍历背包，内层for循环遍历物品。
"""

class Solution:
    def combinationSum4(self, nums: List[int], target: int) -> int:
        
        dp = [0] * (target + 1)
        dp[0] = 1 #必须要有，不然后面递推没有意义
        for i in range(1, target + 1):
            for j in range(len(nums)):
                if i >= nums[j]:
                    dp[i] += dp[i - nums[j]]

        return dp[target]

if __name__ == '__main__':
    target = 4
    nums = [1,2,3]

    solution = Solution()
    result = solution.combinationSum4(nums, target)
    print(result)

