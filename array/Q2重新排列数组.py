from typing import List
class Solution:
    def shuffle(self, nums: List[int], n: int) -> List[int]:
        ans=[0]*(2*n)
        for i in range(0,n):
            ans[2*i]=nums[i]
            ans[2*i+1]=nums[n+i]
        return ans
