#!usr/local/bin/python

class Solution:
    def generate(self, numRows):
        res = [[1]]
        if numRows == 0:
            return []
        
        for i in xrange(1,numRows):
            res += [map(lambda x,y:x+y, res[-1]+[0], [0]+res[-1])]

        return res

if __name__ == '__main__':
    s = Solution()
    numRows = 3
    res = s.generate(numRows)
    
    print res
