from typing import List
max = lambda a, b: b if b > a else a
class Solution:
    def maxSumTrionic(self, nums: List[int]) -> int:
        ans = f1 = f2 = f3 = -inf
        for x, y in pairwise(nums):
            f3 = max(f3,f2) + y if x < y else -inf
            f2 = max(f2,f1) + y if x > y else -inf
            f1 = max(f1, x) + y if x < y else -inf
            ans = max(ans, f3)
        return ans