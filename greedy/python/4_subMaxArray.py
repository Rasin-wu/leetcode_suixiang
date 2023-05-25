#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4]
输出: 6
解释:  连续子数组  [4,-1,2,1] 的和最大，为  6。
"""

class Solution:
    def subMaxArray(self, nums: List) -> int:
        count = 0
        result = -float('inf')

        for item in nums:
            count += item

            if (count > result):
                result = count 

            if count <= 0:
                count = 0
        return result

if __name__ == '__main__':

    nums = [-2,1,-3,4,-1,2,1,-5,4]

    solution = Solution()
    result = solution.subMaxArray(nums)

    print(result)

    
