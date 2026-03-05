from typing import List
class Solution:
    def constructTransformedArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        result = [0] * n
        for i in range(0, n):
            if nums[i] > 0:
                result[i] = nums[(i + nums[i]) % n]
            elif nums[i] < 0:
                result[i] = nums[(i + n + nums[i]) % n]
        return result
