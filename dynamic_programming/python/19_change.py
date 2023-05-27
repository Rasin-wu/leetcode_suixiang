#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定不同面额的硬币和一个总金额。写出函数来计算可以凑成总金额的硬币组合数。假设每一种面额的硬币有无限个。

示例 1:

    输入: amount = 5, coins = [1, 2, 5]
    输出: 4
    解释: 有四种方式可以凑成总金额:
    
    5=5
    5=2+2+1
    5=2+1+1+1
    5=1+1+1+1+1
    示例 2:
    
    输入: amount = 3, coins = [2]
    输出: 0
    解释: 只用面额2的硬币不能凑成总金额3。
    示例 3:
    
    输入: amount = 10, coins = [10]
    输出: 1
    注意，你可以假设：
    
    0 <= amount (总金额) <= 5000
    1 <= coin (硬币面额) <= 5000
    硬币种类不超过 500 种
    结果符合 32 位符号整数
"""

class Solution:
    def change(self, coins: List[int], amount: int) -> int:
        dp = [0] * (amount + 1)
        dp [0] = 1
        # 遍历物品
        for i in range(len(coins)):
            # 遍历背包
            for j in range(coins[i], amount + 1):
                # 完全背包求组合
                dp[j] += dp[j - coins[i]]

        return dp[amount]

if __name__ == '__main__':
    amount = 5
    coins = [1,2,5]

    solution = Solution()
    result = solution.change(coins, amount)
    print(result)

    
