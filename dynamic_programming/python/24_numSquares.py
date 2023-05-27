#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

给你一个整数 n ，返回和为 n 的完全平方数的 最少数量 。

完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：

输入：n = 12
输出：3
解释：12 = 4 + 4 + 4
示例 2：

输入：n = 13
输出：2
解释：13 = 4 + 9
提示：

1 <= n <= 10^4
"""

# dp[j] = min(dp[j - i * i] + 1, dp[j]);
class Solution:
    def numSquares(self, n: int) -> int:
        nums = [i**2 for i in range(1, n + 1) if i**2 < n]
        dp = [float("inf")] * (n + 1)
        dp[0] = 0

        for num in nums:
            for j in range(num, n + 1):
                dp[j] = min(dp[j], dp[j - num] + 1)
        return dp[n] if dp[n] != float("inf") else -1


if __name__ == '__main__':
    n = 12

    solution = Solution()
    result = solution.numSquares(n)
    print(result)


