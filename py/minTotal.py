# usr/local/bin/python

class Solution:
    def __init__(self):
        self.sum = 0
        self.lastRow = 0
        self.lastCol = 0
        self.curRow = 0
        self.curCol = 0

    def totalSum(self,eachRow,triangle):
        self.curRow = self.lastRow + 1
        self.curCol = self.lastCol 
        self.sum += min(triangle[self.curRow][self.curCol],triangle[self.curRow][self.curCol+1])
         
        if triangle[self.curRow][self.curCol] == min(triangle[self.curRow][self.curCol],triangle[self.curRow][self.curCol+1]):
            self.lastCol = self.curCol 
        else:
            self.lastCol = self.curCol+1

        self.lastRow = self.curRow 

    def minimumTotal(self, triangle):
        self.sum = triangle[0][0]
        for i,each in enumerate(triangle):
            if i != 0:
                self.totalSum(each, triangle)

        return self.sum

if __name__ == '__main__':
    solution = Solution()
    triangle= [[1], [2,1], [4,1,6]]

    sum_ = solution.minimumTotal(triangle)

    print sum_
