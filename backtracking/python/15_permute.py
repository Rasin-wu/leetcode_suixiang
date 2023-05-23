#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个 没有重复 数字的序列，返回其所有可能的全排列。

示例:

    输入: [1,2,3]
    输出: [ [1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1] ]]]]]]]]]
"""

class Solution:
    def __init__(self):
        self.result = []
        self.path = []

    def permute(self, nums: List[int]) -> List[List[int]]:
        '''
        因为本题排列是有序的，这意味着同一层的元素可以重复使用，但同一树枝上不能重复使用(usage_list)
        所以处理排列问题每层都需要从头搜索，故不再使用start_index
        '''
        self.result.clear()
        self.path.clear()
        used = [False] * len(nums)

        if (len(nums) == 0):
            return self.result
        self.backtracking(nums, used)
        return self.result

    def backtracking(self, nums: List[int], used: List[bool]) -> List[bool]:
        
        if (len(self.path) == len(nums)):
            self.result.append(self.path[:])
            return

        for i in range(len(nums)):
            # 若遇到self.path里已收录的元素，跳过
            if(used[i] == True):
                continue

            used[i] = True
            self.path.append(nums[i])
            self.backtracking(nums, used)
            used[i] = False
            self.path.pop()


if __name__ == '__main__':

    nums = [1,2,3]
    solution = Solution()

    result = solution.permute(nums)

    for item in result:
        print(item)
