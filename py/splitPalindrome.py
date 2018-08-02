#! usr/local/bin/python

class Solution(object):
    def partition(self,s):
        res = [] 
        if s == "":
            return res 

        length = len(s)
        for i in range(1,length):
            if self.isPalindrome([s[:i]]):
                res.append([s[:i]])
        
        return res 

    def isPalindrome(self, s):
        length = len(s)
        start = 0
        end = length - 1

        while start != end:
            if s[start] != s[end]:
                return False 
            else:
                continue 

        return True 

if __name__ == '__main__':
    s = "aab"

    solution = Solution()
    res = solution.partition(s)

    print res


