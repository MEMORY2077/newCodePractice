class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        n = len(prices)
        dp = [[0]*2]*n
        dp[0][1]=-prices[0]
        for i in range(1,n):
            dp[i][0]=max(dp[i-1][0],dp[i-1][1]+prices[i])
            dp[i][1]=max(dp[i-1][0]-prices[i],dp[i-1][1])
        return dp[n-1][0]