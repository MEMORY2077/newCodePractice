class Solution:
    def trap(self,height:List[int]) -> int:
        n=len(height)
        left=0
        right=n-1
        pre_max=0
        last_max=0
        ans=0
        while left<right:
            pre_max=max(pre_max,height[left])
            last_max=max(last_max,height[right])
            if pre_max>last_max:
                ans+=(last_max-height[right])
                right-=1
            else:
                ans+=(pre_max-height[left])
                left+=1
        return ans