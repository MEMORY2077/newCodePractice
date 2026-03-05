from typing import List
class Solution:
    def removeDuplicates(self, nums: List[int]) -> int:
        n = c = len(nums)
        p = q = 0
        while q != n:
            if nums[p] == nums[q]:
                q += 1
                c -= 1
                continue
            p += 1
            nums[p] = nums[q]
            q += 1
        return c
        