#-*- coding:utf-8 -*-

class Solution():
    def __init__(self,n):
        self.res = []
        self.nthData = [None]*n
        self.createNthData(n)
        self.num = n

    def createNthData(self, n):
        if n<0 :
            return 
        
        for i in xrange(0,n):
            self.nthData[i] = i

    def swap(self, n1, n2):
        temp = self.nthData[n1]
        self.nthData[n1] = self.nthData[n2]
        self.nthData[n2] = temp

    def allCombine(self, begin, end):
        temp = []
        if begin==end:
                for i in xrange(end):
                    temp.append(self.nthData[i])
                self.res.append(temp)

        for i in xrange(begin,end):
            self.swap(begin, i)
            self.allCombine(begin+1, end)
            self.swap(i, begin)
        
        return self.res

    def combine(self, n, k):
        pass
        
if __name__ == '__main__':
    n = 3
    #import pdb
    #pdb.set_trace()
    solution = Solution(n)
    res = solution.allCombine(0,n)
    
    print res
