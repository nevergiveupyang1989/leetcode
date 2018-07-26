# usr/local/bin/python

class Solution(object):
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


if __name__ == '__main__':
    s = Solution()
    nums = [2,1,3,4,6]
    res = s.longestConsecutive(nums)

    print res


