from itertools import combinations
from typing import List
class Solution:
    def f(self,a: List[int],mx: int) -> int:
        a +=[1, mx]
        a.sort()
        return set(y - x for x, y in combinations(a, 2))
    def maximizeSquareArea(self, m: int, n: int, hFences: List[int], vFences: List[int]) -> int:
        MOD = 1000000007
        h_set = self.f(hFences, m)
        v_set = self.f(vFences, n)
        ans = max(h_set & v_set,default = 0)
        return ans*ans % MOD if ans else -1