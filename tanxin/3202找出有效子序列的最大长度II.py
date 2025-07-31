from typing import List
class Solution:
    def maximumLength(self, nums: List[int], k: int) -> int:
        dp=[[0]*k for _ in range(0,k)]
        for x in nums:
            x%=k
            for y in range(0,k):
                dp[y][x]=dp[x][y]+1
        return max(map(max,dp))
