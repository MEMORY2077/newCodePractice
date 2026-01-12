from typing import List
class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        countf = 0
        minimum = 0x3f3f3f3f
        sum = 0
        zeroc = 0
        for row in matrix:
            for now in row:
                sum += abs(now)
                minimum = min(minimum,abs(now))
                if now <0:
                    countf += 1
                elif now == 0:
                    zeroc += 1
        print(sum)
        print(minimum)
        countf -= zeroc
        if countf>0 and countf % 2 == 1:
            sum -= (2*minimum)
        return sum