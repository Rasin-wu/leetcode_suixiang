#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def removeDuplicates(self, s: str) -> str:
        stack = []
        for item in s:
            if stack and item == stack[-1]:
                stack.pop()
            else:
                stack.append(item)
        
        return "".join(stack)


if __name__ == '__main__':
    s = "abbaaca"

    solution = Solution()
    result = solution.removeDuplicates(s)

    print(result)

