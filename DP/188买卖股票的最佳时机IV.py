from typing import List
class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        buy=[0]*k
        sell=[0]*k
        buy[0]=-prices[0]
        sell[0]=0
        for i in range(1,len(prices)):
            buy[0]=max(buy[0],-prices[i])
            sell[0]=max(sell[0],buy[0]+prices[i])
            for j in range(1,k):
                buy[i]=max(buy[i],sell[i-1]-prices[i])
                sell[i]=max(sell[i],buy[i]+prices[i])
        return sell[k-1]