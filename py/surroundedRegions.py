#! usr/local/bin/python

class Solution(object):
    def solve(self, board):
        if board == []:
            return

        rowSize = len(board)
        colSize = len(board[0])

        for i in xrange(rowSize):
            for j in xrange(colSize):
                if i == 0 or i == rowSize-1 or j == 0 or j == colSize-1:
                    if board[i][j] == 'O':
                        self.dfs(board, i, j)
        for i in xrange(rowSize):
            for j in xrange(colSize):
                if board[i][j] == 'O':
                    board[i][j] = 'X'
                if board[i][j] == '*':
                    board[i][j] = 'O'
                         
    
    def dfs(self, board, rowIdx, colIdx):
        row = [0, 0, -1, 1]
        col = [1, -1, 0, 0]

        board[rowIdx][colIdx] = '*'

        for i in xrange(4):
            if rowIdx + row[i]>= 0 and rowIdx + row[i] < len(board) and colIdx + col[i] >= 0 and colIdx+col[i] < len(board[0]) and board[rowIdx+row[i]][colIdx+col[i]] == 'O':
                self.dfs(board, rowIdx+row[i], colIdx+col[i])


if __name__ == '__main__':
    board =[["X","O","X","O","X","O"],["O","X","O","X","O","X"],["X","O","X","O","X","O"],["O","X","O","X","O","X"]] 
    
    s = Solution()
    s.solve(board)

    print board 




                        


