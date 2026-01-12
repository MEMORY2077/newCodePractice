from typing import List
class Solution:
    def maxIncreasingSubarrays(self, nums: List[int]) -> int:
        pre,cnt,ans=0,1,0
        n=len(nums)
        for i in range(1,n):
            if nums[i]>nums[i-1]:
                cnt+=1
            else:
                pre=cnt
                cnt=1
            ans=max(ans,min(cnt,pre))
            ans=max(ans,cnt//2)
        return ans