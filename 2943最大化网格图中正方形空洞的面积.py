from typing import List
class Solution:
    def maximizeSquareHoleArea(self, n: int, m: int, hBars: List[int], vBars: List[int]) -> int:
        def s(a:List)->int:
            a.sort()
            m = 0
            c = 0
            for i,x in enumerate(a):
                if i > 0 and x == a[i - 1] + 1:
                    c += 1
                else:
                    c = 1
                m = max(m, c)
            return m
        res = min(s(hBars), s(vBars)) + 1
        return res * res