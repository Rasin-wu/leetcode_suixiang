#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个非负整数数组，你最初位于数组的第一个位置。

数组中的每个元素代表你在该位置可以跳跃的最大长度。

判断你是否能够到达最后一个位置。

示例  1:

输入: [2,3,1,1,4]
输出: true
解释: 我们可以先跳 1 步，从位置 0 到达 位置 1, 然后再从位置 1 跳 3 步到达最后一个位置。
示例  2:

输入: [3,2,1,0,4]
输出: false
解释: 无论怎样，你总会到达索引为 3 的位置。但该位置的最大跳跃长度是 0 ， 所以你永远不可能到达最后一个位置
"""

class Solution:
    def canJump(self, nums: List[int]) -> bool:
        cover = 0
        
        if len(nums) == 1:
            return True
        
        index = 0
        while index <= cover:
            cover = max(nums[index] + index, cover)
            index += 1
            if cover > len(nums):
                return True

        return False

if __name__ == '__main__':
    nums = [2, 3, 1, 1, 4]

    solution = Solution()
    result = solution.canJump(nums)

    print(result)
        