#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。返回一个表示每个字符串片段的长度的列表。

示例：

输入：S = "ababcbacadefegdehijhklij"
输出：[9,7,8] 解释： 划分结果为 "ababcbaca", "defegde", "hijhklij"。 每个字母最多出现在一个片段中。 像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。
提示：

S的长度在[1, 500]之间。
S只包含小写字母 'a' 到 'z' 。
"""

class Solution:
    def partitionLabels(self, s: str) -> List[int]:
        hash = [0] * 26

        for i in range(len(s)):
            hash[ord(s[i]) - ord('a')] = i

        result = []
        left = 0 
        right = 0
        for i in range(len(s)):
            right = max(right, hash[ord(s[i]) - ord('a')])

            if i == right:
                result.append(right - left + 1)
                left = i + 1
        return result
    
if __name__ == '__main__':
    s = "ababcbacadefegdehijhklij"
    solution = Solution()

    result = solution.partitionLabels(s)
    print(result)