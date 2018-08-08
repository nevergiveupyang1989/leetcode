#! usr/local/bin/python

class Solution(object):
    def partition(self,s):
        res = [] 
        if s == "":
            return res 

        length = len(s)
        for i in range(1,length+1):
            if self.isPalindrome([s[:i]]):
                res.append([s[:i]])
            if self.isPalindrome(s[i:]):
                res.append(s[i:])
        
        return res 

    def isPalindrome(self, s):
        if s == []:
            return False 

        length = len(s)
        start = 0
        end = length - 1

        while start != end:
            if start < end and s[start] != s[end]:
                start += 1
                end -= 1
                return False 
            else:
                start += 1
                end -= 1
                continue 

        return True 

if __name__ == '__main__':
    s = "aab"

    solution = Solution()
    res = solution.partition(s)

    print res


