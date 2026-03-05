class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        minprice=prices[0]
        ans=0
        for i in range(n):
            ans = max(ans,prices[i]-minprice)
            minprice=min(minprice,prices[i])
        return ans
            