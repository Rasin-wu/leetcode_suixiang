#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。

示例：

输入：

A: [1,2,3,2,1]
B: [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3, 2, 1] 。
提示：

1 <= len(A), len(B) <= 1000
0 <= A[i], B[i] < 100`
"""

#dp[i][j] ：以下标i - 1为结尾的A，和以下标j - 1为结尾的B，最长重复子数组长度为dp[i][j]。 （特别注意： “以下标i - 1为结尾的A” 标明一定是 以A[i-1]为结尾的字符串 ）
class Solution:
    def findLength(self, nums1: List[int], nums2: List[int]) -> int:
        if len(nums1) == 0 or len(nums2) == 0:
            return 0
        
        dp = [[0] * (len(nums1) + 1) for _ in range(len(nums2) + 1)]
        result = 0
        for i in range(1, len(nums1) + 1):
            for j in range(1, len(nums2) + 1):
                if nums1[i - 1] == nums2[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                if result < dp[i][j]:
                    result = dp[i][j] 
        return result
    
if __name__ == '__main__':
    nums1 = [1,2,3,2,1]
    nums2 = [3,2,1,4,7]

    solution = Solution()
    result = solution.findLength(nums1, nums2)
    print(result)