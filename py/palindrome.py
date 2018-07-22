#usr/local/bin/python

class Solution(object):
    def isPalindrome(self, s):
        if s == "":
            return True
        
        size = len(s)
        begin = 0
        end = size - 1

        while(begin <= end):
            if not (s[begin] >= '0' and s[begin] <= '9' or s[begin]>='a' and
            s[begin]<='z' or s[begin] >= 'A' and s[begin] <= 'Z'):
                begin += 1
                continue 

            if not (s[end] >= '0' and s[end] <= '9' or s[end]>='a' and s[end]<='z' or
            s[end]>='A' and s[end]<='Z'):
                end = end -1
                continue 

            if not (s[begin] == s[end] or s[begin].lower() == s[end].lower()):
                return False

            begin += 1
            end -= 1

        return True 


if __name__ =='__main__':
    s = Solution()
    str_ = "0P"
    res = s.isPalindrome(str_)

    print res
            




