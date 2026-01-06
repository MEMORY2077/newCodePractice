from math import sqrt
class Solution:
    def numSquares(self, n: int) -> int:
        m=int(sqrt(n)+1)
        dp=[[0x3f3f3f3f]*(n+1)]*(m+1)
        for i in range(0,n+1):
            dp[0][i]=0
        for i in range(1,m+1):
            for j in range(1,n+1):
                dp[i][j]=dp[i-1][j]
                if(j-i*i>=0):
                    dp[i][j]=min(dp[i][j],dp[i][j-i*i]+1)
        return dp[m][n]