from typing import List
class Solution:
    def largestSquareArea(self, bottomLeft: List[List[int]], topRight: List[List[int]]) -> int:
        res = 0
        for i,((bx,by),(tx,ty)) in enumerate(zip(bottomLeft,topRight)):
            for j in range(i):
                bx2, by2 = bottomLeft[j]
                tx2, ty2 = topRight[j]
                width = min(tx, tx2) - max(bx, bx2)
                height = min(ty, ty2) - max(by, by2)
                res = max(res, min(width, height))
        return res ** 2