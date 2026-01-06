from typing import List
class Solution:
    def numOfWays(self, n: int) -> int:
        mod = 1000000007
        PreA = 6
        PreB = 6
        for i in range(1,n):
            tmpA = (PreA * 2 + PreB * 2)//mod
            tmpB = (PreA * 2 + PreB * 3)//mod
            PreA = tmpA
            PreB = tmpB
        return PreA + PreB