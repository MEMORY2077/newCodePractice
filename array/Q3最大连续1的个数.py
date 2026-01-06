from typing import List
class Solution:
    def findMaxConsecutiveOnes(self, nums: List[int]) -> int:
        maximum=0
        count=0
        nums.append(0)
        for num in nums:
            if(num==1):
                count+=1
            else:
                maximum=max(count,maximum)
                count=0
        return maximum
