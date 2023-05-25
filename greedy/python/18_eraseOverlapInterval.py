#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个区间的集合，找到需要移除区间的最小数量，使剩余区间互不重叠。

注意: 可以认为区间的终点总是大于它的起点。 区间 [1,2] 和 [2,3] 的边界相互“接触”，但没有相互重叠。

示例 1:

输入: [ [1,2], [2,3], [3,4], [1,3] ]
输出: 1
解释: 移除 [1,3] 后，剩下的区间没有重叠。
示例 2:

输入: [ [1,2], [1,2], [1,2] ]
输出: 2
解释: 你需要移除两个 [1,2] 来使剩下的区间没有重叠。
示例 3:

输入: [ [1,2], [2,3] ]
输出: 0
解释: 你不需要移除任何区间，因为它们已经是无重叠的了。
"""

class Solution:
    def eraseOverlapInterval(self, intervals: List[List[int]]) -> int:
        if len(intervals) == 0: return 0

        intervals.sort(key = lambda x : x[1])
        count = 1
        end = intervals[0][1]
        
        for i in range(len(intervals)):
            if end < intervals[i][0]:
                count += 1
                end = intervals[i][1]

        return len(intervals) - count

if __name__ == '__main__':
    intervals = [ [1,2], [2,3], [3,4], [1,3] ]
    solution = Solution()

    resut = solution.eraseOverlapInterval(intervals)
    print(resut)