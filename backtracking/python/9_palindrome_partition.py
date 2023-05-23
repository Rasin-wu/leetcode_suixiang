#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

返回 s 所有可能的分割方案。

示例: 输入: "aab" 输出: [ ["aa","b"], ["a","a","b"] ]
"""

class Solution:
    def __init__(self) -> None:
        self.result = []
        self.path = []

    def palindromePatition(self, s: str) -> List[List[str]]:
        
        if (len(s) == 0):
            return
        self.result.clear()
        self.path.clear()

        self.backtracking(s, 0)
        return self.result

    def backtracking(self, s: str, startIndex: int) -> None:
        
        if (startIndex >= len(s)):
            self.result.append(self.path[:])
        
        for i in range(startIndex, len(s)):
            #注意不是 s[startIndex, i + 1]
            temp = s[startIndex : i + 1]
            if temp == temp[::-1]:
                self.path.append(temp)
                self.backtracking(s, i + 1)
                self.path.pop()
            else:
                continue

if __name__ == '__main__':
    s = "aab"
    
    solution = Solution()
    result = solution.palindromePatition(s)
    print(len(result))
    for item in result:
        for str_1 in item:
            print(str_1, end = ' ')
        print()