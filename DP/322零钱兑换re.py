from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        n=len(coins)
        dp=[0x3f3f3f3f]*(amount+1)
        dp[0]=0
        for money in coins:
            for i in range (0,amount+1):
                if i-money>=0:
                    dp[i]=min(dp[i],dp[i-money]+1)
        if dp[amount]==0x3f3f3f3f:
            return -1
        return dp[amount]