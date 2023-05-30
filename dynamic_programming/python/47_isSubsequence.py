#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

示例 1： 输入：s = "abc", t = "ahbgdc" 输出：true

示例 2： 输入：s = "axc", t = "ahbgdc" 输出：false

提示：

0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。
"""

class Solution:
    def isSubSequence(self, s: str, t: str) -> bool:
        dp = [[0] * (len(t) + 1) for _ in range(len(s) + 1)]
        dp[0][0] = 0
        for i in range(1, len(s) + 1):
            for j in range(1, len(t) + 1):
                if s[i - 1] == t[j - 1]:
                    dp[i][j] = dp[i - 1][j - 1] + 1
                else:
                    dp[i][j] = dp [i][j - 1]

        if dp[-1][-1] == len(s):
            return True
        return False
    
if __name__ == '__main__':
    s = "abc"
    t = "ahbgdc"

    solution = Solution()
    result = solution.isSubSequence(s, t)
    print(result)