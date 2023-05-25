#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给出一个区间的集合，请合并所有重叠的区间。

示例 1:

输入: intervals = [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
示例 2:

输入: intervals = [[1,4],[4,5]]
输出: [[1,5]]
解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
注意：输入类型已于2019年4月15日更改。 请重置默认代码定义以获取新方法签名。
"""

class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if len(intervals) == 0:
            return intervals
        # 以左边界排序
        intervals.sort(key=lambda x : x[0])
        result = []
        result.append(intervals[0])
        for i in range(1, len(intervals)):
            last = result[-1]

            if intervals[i][0] < last[1]:
                #动态修改最后一个元素的左边位置
                result[-1] = [last[0], max(last[1], intervals[i][1])]
            else:
                result.append(intervals[i])

        return result
    
if __name__ == '__main__':
    intervals = [[1,3],[2,6],[8,10],[15,18]]
    solution = Solution()

    result = solution.merge(intervals)
    for item in result:
        print(item)