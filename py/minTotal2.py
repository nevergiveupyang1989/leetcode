# usr/local/bin/python


class Solution:
    def maxProfit(self, prices):
        sum_ = 0
        if prices == []:
            return 0

        max_ = 0
        min_ = prices[0]

        for i in xrange(1,len(prices)):
            max_ = max(max_, prices[i]-min_)
            min_ = min(min_, prices[i])

            if prices[i]<prices[i-1]:
                sum_ += max_ 
                max_ = 0
                min_ = prices[i]

        return sum_ 

if __name__ == '__main__':
    solution = Solution()
    prices = [7,1,5,3,6,4]
    res = solution.maxProfit(prices)
    
    print res

