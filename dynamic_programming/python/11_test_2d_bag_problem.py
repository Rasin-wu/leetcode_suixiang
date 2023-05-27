#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def test_2d_bag_problem(self, bag_size: int, weight: List[int], value: List[int]) -> int:
        rows, cols = len(weight), bag_size + 1
        dp = [[0 for _ in range(cols)] for _ in range(rows)]  #2d初始化

        for i in range(rows):
            dp[i][0] = 0

        #first_item_weight, first_item_value = weight[0], value[0]
        for j in range(cols):
            if weight[0] <= j:
                dp[0][j] = value[0]

        # 更新dp数组：先边离物品，再遍历背包
        for i in range(1, len(weight)):
            #cur_weight, cur_val = weight[i], value[i]
            for j in range(1, cols):
                if weight[i] > j:
                    dp[i][j] = dp[i - 1][j]   #背包装不下当前物品
                else:
                    # 定义dp数组: dp[i][j] 前i个物品里，放进容量为j的背包，价值总和最大是多少。
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i])

        return dp[rows - 1][cols - 1]

if __name__ == '__main__':
    bag_size = 4
    weight = [1, 3, 4]
    value = [15, 20, 30]

    solution = Solution()
    result = solution.test_2d_bag_problem(bag_size, weight, value)
    print(result)

