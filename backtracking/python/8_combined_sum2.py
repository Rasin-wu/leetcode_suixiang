#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。

candidates 中的每个数字在每个组合中只能使用一次。

说明： 所有数字（包括目标数）都是正整数。解集不能包含重复的组合。

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,

[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
"""

class Solution:
    def __init__(self):
        self.result = []
        self.path = []

    def combinedSum2(self, candinates: List[int], target: int) -> List[List[int]]:
        self.result.clear()
        self.path.clear()

        # 必须提前进行数组排序，避免重复
        candinates.sort()
        used = [False] * len(candinates)

        self.backtracking(candinates, used, target, 0, 0)
        return self.result

    def backtracking(self, candinates: List[int], used: List[int], target: int, nowSum: int, startIndex: int) -> None:
        # base Case
        if (len(candinates) == 0):
            return
        if (nowSum == target):
            self.result.append(self.path[:])
            return

        if (nowSum > target):
            return

        # 单层递归逻辑 
        for i in range(startIndex, len(candinates)):

            #跳过统一树层使用过的元素
            #若数组中前后元素值相同，但前者却未被使用(used == False)，说明是for loop中的同一树层的相同元素情况
            if(i > 0 and used[i - 1] == False and candinates[i] == candinates[i -1]):
                continue
            used[i] = True
            self.path.append(candinates[i])
            nowSum += candinates[i]
            self.backtracking(candinates, used, target, nowSum, i + 1)
            used[i] = False
            self.path.pop()
            nowSum -= candinates[i]

if __name__ == '__main__':
    candinates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    
    solution = Solution()
    result = solution.combinedSum2(candinates, target)

    print(len(result))

    for item in result:
        print(item)
