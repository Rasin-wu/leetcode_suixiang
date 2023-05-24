#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。

给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。

每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
"""

class Solution:
    def __init__(self) -> None:
        self.result = []

    def solveQueeen(self, n: int) -> List[List[str]]:

        self.result.clear()

        chessboard = [['.'] * n for _ in range(n)]
        
        self.backtracking(chessboard, n, 0)
        return self.result

    def backtracking(self, chessboard: List[List[str]], n: int, row: int) -> None:

        # 如果走到最后一行，就是一个解
        if (row == n):
            str_list = [] 
            for item in chessboard:
                str_temp = "".join(item)
                str_list.append(str_temp)
                
            self.result.append(str_list)

        for col in range(n): 
            if not self.isValid(chessboard, row, col):
                continue

            chessboard[row][col] = 'Q'
            self.backtracking(chessboard, n, row + 1)
            chessboard[row][col] = '.'

    def isValid(self, chessboard: List[List[str]], row: int, col: int) -> None:
    
        # 判断同一列是否有冲突
        for i in range(len(chessboard)):
            if (chessboard[i][col] == 'Q'):
                return False
        #判断左上角有没有冲突
        i = row - 1
        j = col - 1
        while i >= 0 and j >= 0:
            if (chessboard[i][j] == 'Q'):
                return False
            j -= 1
            i -= 1

        #判断右上角有没有冲突
        i = row - 1
        j = col + 1
        while i >= 0 and j < len(chessboard):
            if (chessboard[i][j] == 'Q'):
                return False
            j += 1
            i -= 1

        return True
        

if __name__ == '__main__':
    n = 4
    solution = Solution()

    result = solution.solveQueeen(n)

    for item in result:
        print(item)