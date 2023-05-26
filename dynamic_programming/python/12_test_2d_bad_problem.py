#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def test_2d_bag_problem(self, bag_size: int, weight: List[int], value: List[int]) -> int:

        dp = [0] * (bag_size + 1)

        #必须要先遍历物品，再遍历背包容量
        for i in range(len(weight)):
            for j in range(bag_size, weight[i] - 1, -1):
                dp[j] = max(dp[j], dp[j - weight[i]] + value[i])

        return dp[bag_size]



if __name__ == '__main__':
    bag_size = 4
    weight = [1, 3, 4]
    value = [15, 20, 30]

    solution = Solution()
    result = solution.test_2d_bag_problem(bag_size, weight, value)
    print(result)
