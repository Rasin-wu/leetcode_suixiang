#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。

说明：解集不能包含重复的子集。

示例:

    输入: [1,2,2]
    输出: [ [2], [1], [1,2,2], [2,2], [1,2], [] ]]]]]]]]]
"""

class Solution:
    def __init__(self):
        self.path = []
        self.result = []

    def subsetsWithDuplicat(self, nums: List[int]) -> List[List[int]]:
        self.path.clear()
        self.result.clear()

        used = [False] * len(nums)

        if(len(nums) == 0):
            return self.result

        nums.sort()
        self.backtracking(nums, used, 0)
        return self.result

    def backtracking(self, nums: List[int], used: List[bool], startIndex: int) -> None:
        
        self.result.append(self.path[:])

        if (startIndex >= len(nums)):
            return

        for i in range(startIndex, len(nums)):

            if (i > 0 and nums[i] == nums[i - 1] and used[i - 1] == False):
                continue

            self.path.append(nums[i])
            used[i] = True
            self.backtracking(nums, used, i + 1)
            self.path.pop()
            used[i] = False


if __name__ == '__main__':

    nums = [1,2,2]
    solution = Solution()

    result = solution.subsetsWithDuplicat(nums)

    print(len(result))

    for item in result:
        print(item)

