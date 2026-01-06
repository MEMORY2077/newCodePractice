from typing import List
from collections import defaultdict
from math import sqrt
class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        count = defaultdict(int)
        ans = 0
        add = defaultdict(int)
        for num in nums:
            if count[num] != 0:
                if count[num] == 4:
                    ans += add[num]
                continue
            sn = int(sqrt(num))
            for i in range (1,sn + 1):
                if num % i == 0:
                    add[num] += (i + num // i)
                    if i*i != num:
                        count[num] += 2  
                    else:
                        count[num] += 1
                    if count[num] > 4:
                        break
            if count[num] == 4:
                ans += add[num]
        return ans
