#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def validMountainArray(self, nums: List[int]) -> bool:
        if (len(nums) < 3): return False
        left = 0; right = len(nums) - 1
        while (left < len(nums) - 1 and nums[left + 1] > nums[left]):
            left += 1
        while (right > 0 and nums[right - 1] > nums[right]):
            right -= 1

        if(left == right): return True
        return False
        

if __name__ == '__main__':
    nums = [0,3,2,1]
    solution = Solution()
    result = solution.validMountainArray(nums)
    print(result)
