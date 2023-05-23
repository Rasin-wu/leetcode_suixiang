#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的数字可以无限制重复被选取。

说明：

所有数字（包括 target）都是正整数。
解集不能包含重复的组合。

示例 1：

输入：candidates = [2,3,6,7], target = 7,
所求解集为： [ [7], [2,2,3] ]
示例 2：

输入：candidates = [2,3,5], target = 8,
所求解集为： [ [2,2,2,2], [2,3,3], [3,5] ]
#算法公开课
"""

class Solution:
    def __init__(self):
        self.result = []
        self.path = []

    def combinedSum(self, candinates: List[int], target: int) -> List[List[int]]:
        self.result.clear()
        self.path.clear()

        if (len(candinates)) == 0:
            return

        self.backtracking(candinates, target, 0, 0)
        return self.result

    def backtracking(self, candinates: List[int], target: int, nowSum: int, startIndex: int) -> None:
        if (nowSum == target):
            self.result.append(self.path[:])  #因为是shallow copy，所以不能直接传入self.path
            return
        if (nowSum > target):
            return
        
        for i in range(startIndex, len(candinates)):
            nowSum += candinates[i]
            self.path.append(candinates[i])
            self.backtracking(candinates, target, nowSum, i)
            nowSum -= candinates[i]
            self.path.pop()


if __name__ == '__main__':
    candinates = [2, 3, 6, 7]
    target = 7

    solution = Solution()
    result = solution.combinedSum(candinates, target)

    print(len(result))
    for item in result:
        print([item[:]])
    