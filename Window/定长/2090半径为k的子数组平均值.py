class Solution:
    def getAverages(self, nums: List[int], k: int) -> List[int]:
        ans=[-1]*len(nums)
        s=0
        for i, x in enumerate(nums):
            s+=x
            if i<k*2:
                continue
            ans[i-k]=s//(k*2+1)
            s-=nums[i-k*2]
            
        return ans
        