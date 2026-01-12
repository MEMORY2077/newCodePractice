from typing import List
class Solution:
    def change(self, amount: int, coins: List[int]) -> int:
        m=len(coins)
        n=amount+1
        dp=[[0]*m]*n
        for i in range (1,n+1):
            if i//coins[0]==0:
                dp[0][i]=1
        for i in range (1,m):
            for j in range (1,n+1):
                dp[i][j]=dp[i-1][j]
                if(j-coins[i]>=0):dp[i][j]+=dp[i][j-coins[i]]
        return dp[m][n]