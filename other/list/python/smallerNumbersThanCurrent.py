#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        res = [:]
        hash = dict()
        nums.sort()
        for i, item in enumerate(res):
            hash[i] = i

        for i, item in enumerate(nums):
            res[i] = hash[nums[i]]

        return res
    
if __name__ == '__main__':
    nums = [8,1,2,2,3]
    solution = Solution()

    result = solution.smallerNumbersThanCurrent(nums)
    for i in result:
        print(i)
