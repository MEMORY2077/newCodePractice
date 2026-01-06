from typing import List
from collections import defaultdict
class Solution:
    def pyramidTransition(self, bottom: str, allowed: List[str]) -> bool:
        groups = defaultdict(list)
        for s in allowed:
            groups[s[:2]].append(s[2])
        n = len(bottom)
        pyramid=[['']*(i+1)for i in range(n)]
        pyramid[-1]=bottom
        def dfs(i: int, j: int)->bool:#要填i,j了
            if(i < 0):
                return True
            if j == i + 1:#这行写完了，写下一行
                return dfs(i - 1, 0)
            for top in groups[pyramid[i+1][j]+pyramid[i+1][j+1]]:
                pyramid[i][j] = top
                if dfs(i, j+1):
                    return True
            return False
        return dfs(n-2,0)
        