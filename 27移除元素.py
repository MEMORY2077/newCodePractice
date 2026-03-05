from typing import List
class Solution:
    def removeElement(self, nums: List[int], val: int) -> int:
        p = q = 0
        n = len(nums)
        count = n
        while q < n:
            if nums[q] == val:
                q += 1
                count -= 1
                continue
            nums[p] = nums[q]
            p += 1
            q += 1
        return count