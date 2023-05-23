#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例: 输入: nums = [1,2,3] 输出: [ [3],   [1],   [2],   [1,2,3],   [1,3],   [2,3],   [1,2],   [] ]
"""

class Solution:
    def __init__(self) -> None:
        self.result = []
        self.path = []

    def subsets(self, nums: List[int]) -> List[List[int]]:
        self.result.clear()
        self.path.clear()

        if (len(nums) == 0):
            return self.result

        self.backtracking(nums, 0)
        return self.result 
    
    def backtracking(self, nums: List[int], startIndex: int) -> None:

        self.result.append(self.path[:])

        if (startIndex >= len(nums)):
            return
        for i in range(startIndex, len(nums)):
            self.path.append(nums[i])
            self.backtracking(nums, i + 1)
            self.path.pop()


if __name__ == '__main__':
    nums = [1, 2, 3]

    solution = Solution()
    result = solution.subsets(nums)
    print(len(result))

    for item in result:
        print(item)
    
