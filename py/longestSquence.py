# usr/local/bin/python

class Solution(object):
    '''
    def longestConsecutive(self,nums):
        if nums is None:
            return 0

        length = 1
        maxLength = 0

        nums.sort()
        for i in xrange(len(nums)):
            if i+1<len(nums) and nums[i] + 1 == nums[i+1]:
                length += 1
                maxLength = max(maxLength, length)
            else:
                length = 1

        return maxLength 
    '''

    def longestConsecutive(self,num):
        numsDict = {}
        maxLength = 0
        tmp = 0

        if num is None:
            return maxLength 

        for i in num:
            if i not in numsDict.keys(): 
                preidx = i
                latteridx = i
                numsDict[i] = 1 
                
                while preidx in numsDict.keys():
                    preidx -= 1
                
                if preidx+1 != i:
                    numsDict[i] += numsDict[preidx+1]

                while latteridx in numsDict.keys():
                    latteridx += 1
                
                if latteridx-1 != i:
                    numsDict[latteridx-1] += numsDict[i]
                
                numsDict[preidx+1] = numsDict[latteridx-1]
                 
        for i in numsDict.values():
            if i > maxLength:
                maxLength = i
        
        return maxLength

if __name__ == '__main__':
    s = Solution()
    nums = [2,1,3,4,6]
    res = s.longestConsecutive(nums)

    print res


