class Solution:
    def maxArea(self, height: List[int]) -> int:
        maximum=0
        sz=len(height)
        left=0
        right=sz-1
        while left<right:
            maximum=max(maximum,(right-left)*min(height[left],height[right]))
            if(height[left]<height[right]):
                left+=1
            else:
                right-=1
        return maximum