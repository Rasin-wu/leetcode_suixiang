#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

class Solution:
    def isValid(self, s: str) -> bool:

        stack = []

        for item in s:
            if item == '(':
                stack.append(')')
            elif item == '[':
                stack.append(']')
            elif item == '{':
                stack.append('}')
            elif not stack or stack[-1] != item:
                return False
            else: stack.pop()
            
        return True if not stack else False



from typing import List

if __name__ == '__main__':
    s = "()[]{}])"

    solution = Solution()
    result = solution.isValid(s)

    print(result)

