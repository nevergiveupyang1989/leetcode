#! usr/local/bin/python

class Solution(object):
    def solve(self, board):
        if board == []:
            return

        rowSize = len(board[0])
        colSize = len(board)

        for i in xrange(rowSize):
            for j in xrange(colSie):
                if i == 0 or i == rowSize-1 or j == 0 or j == colSize:
                    if board[i][j] == 'O':
                        dfs(board, i, j)

        for i in xrange(rowSize):
            for j in xrange(colSie):
                if board[i][j] == '*':
                    board[i][j] = 'O'
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                         
    
    def dfs(self, board, rowIdx, colIdx):
        row = [0, 0, -1, 1]
        col = [1, -1, 0, 0]

        board[rowIdx][colIdx] = '*'

        for i in xrange(4):
            if rowIdx + row[i]>= 0 and rowIdx + row[i] <= len(board[0]) and colIdx + col[i] >= 0 and colIdx+col[i] <= len(board) and board[rowIdx+row[i]][colIdx+col[i]] == 'O':
                self.dfs(board, rowIdx+row[i], colIdx+col[i])


if __name__ == '__main__':
    pass 


                        


