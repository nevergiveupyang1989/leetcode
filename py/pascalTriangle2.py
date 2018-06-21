#usr/local/bin/python

class Solution:
    def pascalTriangle2(self, nTh):
        res = [-1]*nTh
        tmp=[[1]*100]*100 
        if nTh < 0:
            return res 

        for i in xrange(0,nTh):
            for j in xrange(0,i+1):
                if j == 0 or i == j:
                    res[j] = 1
                    tmp[i][j] = 1
                else:
                    res[j] = tmp[i-1][j-1]+tmp[i-1][j]

        return res 


if __name__ == '__main__':
    solution = Solution()
    res = solution.pascalTriangle2(3)

    print res
                
        

