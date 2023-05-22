#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

"""
给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。

示例: 输入: n = 4, k = 2 输出: [ [2,4], [3,4], [2,3], [1,2], [1,3], [1,4], ]
"""

from typing import List

class Solution:
    def combine(self, n, k):

        result = []
        path = []

        def backtracking(n, k, startIndex):

            if(len(path) == k):
                print(path)
                result.append(path[:])
                return
            
            # 剪枝， 最后k - len(path)个节点直接构造结果，无需递归
            lastIndex = n - (k - len(path)) + 1

            for x in range(startIndex, lastIndex):
                path.append(x)
                backtracking(n, k, x + 1)
                path.pop()

        backtracking(n, k, 1)
        return result


if __name__ == '__main__':
    n = 4
    k = 2

    solution = Solution()
    result = solution.combine(n, k)
    print(result)

