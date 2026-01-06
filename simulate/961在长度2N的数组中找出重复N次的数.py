from typing import List
from collections import defaultdict
class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        a=defaultdict(int)
        for now in nums:
            if a[now] !=0:
                return now
            a[now] += 1
        return -1