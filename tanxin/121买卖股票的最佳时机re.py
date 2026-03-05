class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n=len(prices)
        minp=[0]*n
        minp[0]=prices[0]
        for i in range(1,n):
            minp[i]=min(minp[i-1],prices[i])
        ans=0
        for i in range(n):
            ans=max(ans,prices[i]-minp[i])
        return ans
            