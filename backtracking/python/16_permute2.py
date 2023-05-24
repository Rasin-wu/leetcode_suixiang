#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：

输入：nums = [1,1,2]
输出： [[1,1,2], [1,2,1], [2,1,1]]
示例 2：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
提示：

1 <= nums.length <= 8
-10 <= nums[i] <= 10
"""

class Solution:
    def __init__(self):
        self.path = []
        self.result = []

    def permute2(self, nums: List[int]) -> List[List[int]]:
        used = [False] * len(nums)
        
        if (len(nums) == 0):
            return self.result
        self.path.clear()
        self.result.clear()

        self.backtracking(nums, used) 
        return self.result

    def backtracking(self, nums: List[int], used: List[bool]) -> None:
        if (len(self.path) == len(nums)):
            self.result.append(self.path[:])
            return
        for i in range(len(nums)):
            #同一数层不重复的判断条件
            if (i > 0 and nums[i] == nums[i - 1] and used[i - 1] == False):
                continue
            #同一树枝不重复的判断条件
            if (used[i] == True):  # if not used[i]:
                continue

            used[i] = True
            self.path.append(nums[i])
            self.backtracking(nums, used)
            used[i] = False
            self.path.pop()

if __name__ == '__main__':

    nums = [1,1,2,3]
    solution = Solution()

    result = solution.permute2(nums)

    for item in  result:
        print(item)
            