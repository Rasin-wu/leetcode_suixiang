#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

class Solution:
    def ClimbStair(self, n: int) -> int:

        dp = [0] * (n + 1)
        dp[0] = 1

        m = 2

        for i in range(1, n + 1):
            for j in range(1, m + 1):
                if i >= j:
                    dp[i] += dp[i - j]
        return dp[n]
