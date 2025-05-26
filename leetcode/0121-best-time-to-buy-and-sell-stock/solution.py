class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        mini=prices[0]
        diff=0
        for i in range (len(prices)):
            if prices[i]<mini:
                mini=prices[i]
            elif prices[i]-mini>diff:
                diff=prices[i]-mini
        return diff
        
