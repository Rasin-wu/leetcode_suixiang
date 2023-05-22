#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

"""
找出所有相加之和为 n 的 k 个数的组合。组合中只允许含有 1 - 9 的正整数，并且每种组合中不存在重复的数字。

说明：

所有数字都是正整数。
解集不能包含重复的组合。
示例 1: 输入: k = 3, n = 7 输出: [[1,2,4]]

示例 2: 输入: k = 3, n = 9 输出: [[1,2,6], [1,3,5], [2,3,4]]]]]]]]
"""

from typing import List

class Solution:
    def __init__(self):
        self.res = []
        self.sum_now = 0
        self.path = []

    def combinationSum3(self, k: int, n: int) -> [[int]]:
         self.backtracking(k, n, 1)
         return self.res

    def backtracking(self, k: int, n: int, startIndex: int):
         if self.sum_now > n:
             return
         if len(self.path) == k:
             if self.sum_now == n:
                 self.res.append(self.path[:])
             return
         for i in range(startIndex, 10 - (k - len(self.path)) + 1):
             self.path.append(i)
             self.sum_now += i
             self.backtracking(k, n, i + 1)
             self.path.pop()
             self.sum_now -= i

if __name__ == '__main__':
    k = 3
    n = 7
    solution = Solution()
    result = solution.combinationSum3(k, n)
    print(result)
