from collections import defaultdict
from typing import List
class Solution:
    def maxFrequency(self,nums: List[int],k:int,numOperations:int)->int:
        cnt=defaultdict(int)
        diff=defaultdict(int)
        for x in nums:
            cnt[x]+=1
            diff[x-k]+=1
            diff[x+k+1]-=1
            diff[x]
        sumD=0
        ans=0
        for x,d in sorted(diff.items()):
            sumD+=d
            ans=max(ans,min(sumD,numOperations+cnt[x]))
        return ans