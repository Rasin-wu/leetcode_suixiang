#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def test_complect_bag_problem(self, bagSize: int, weight: List[int], value: List[int]):
        dp  = [0] * (bagSize + 1)
        
        for i in range(len(weight)):
            for j in range(weight[i], bagSize + 1):
                dp[j] = max(dp[j], dp[j -weight[i]] + value[i])

        return dp[bagSize]


if __name__ == '__main__':
    bagSize = 4
    weight = [1, 3, 4]
    value = [15, 20, 30]

    solution = Solution()
    result = solution.test_complect_bag_problem(bagSize, weight, value)
    print(result)
