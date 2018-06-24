#usr/local/bin/python

class Solution:
    def maxProfit(self, prices):
        if prices == []:
            return 0
        max = 0

        for i in xrange(len(prices)):
            for j in xrange(i,len(prices)):
                if prices[i] < prices[j]:
                    if prices[j]-prices[i] > max:
                        max = prices[j] - prices[i]
        
        return max 

if __name__ == '__main__':
    solution = Solution()
    prices = [7,1,5,3,6,4]
    res = solution.maxProfit(prices)

    print res

                        
