#!/mnt/lustre02/jiangsu/aispeech/home/xmw01/tools/anaconda3/bin/python
# -*- coding: UTF-8 -*-

from typing import List

"""
编写一个程序，通过填充空格来解决数独问题。

一个数独的解法需遵循如下规则： 数字 1-9 在每一行只能出现一次。 数字 1-9 在每一列只能出现一次。 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。 空白格用 '.' 表示。

提示：

给定的数独序列只包含数字 1-9 和字符 '.' 。
你可以假设给定的数独只有唯一解。
给定数独永远是 9x9 形式的。
"""

class Solution:
    def __init__(self, board: List[List[str]]):
        self.board = board

    def solveSudoku(self) -> List[List[str]]:
        self.backtracking(board)

    def backtracking(self, board: List[List[str]]) -> bool:

        #若有解, 返回True
        for row in range(len(board)):
            for col in range(len(board[0])):
                if (board[row][col] != '.'):
                    continue
                
                for i in range(1, 10):
                    if self.isValid(row, col, i, board):
                        board[row][col] = str(i)

                        if self.backtracking(board): return True
                        board[row][col] = '.'

                return False

        return True
                    

    def isValid(self, row: int, col: int, val: int, board: List[List[str]]) -> bool:
        
        #判断同一行是否冲突
        for i in range(9):
            if board[row][i] == str(val):
                return False

        #判断同一列是否冲突
        for j in range(9):
            if board[j][col] == str(val):
                return False

        #判断同一九宫格是否有冲突
        start_row = (row // 3) * 3
        start_col = (row // 3) * 3

        for i in range(start_row, start_row + 3):
            for j in range(start_col, start_col + 3):
                if board[i][j] == str(val):
                    return False

        return True






