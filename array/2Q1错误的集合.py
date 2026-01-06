from typing import List
class Solution:
    def findErrorNums(self, nums: List[int]) -> List[int]:
        nums=sorted(nums)
        n=len(nums)
        for i in range(0,n):
            if nums[i]!=i+1:   
                return [nums[i],i+1]
        return []