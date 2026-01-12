from typing import List
class Solution:
    def findJudge(self, n: int, trust: List[List[int]]) -> int:
        id=[0]*(n+1)
        od=[0]*(n+1)
        for now in trust:
            id[now[1]]+=1
            od[now[0]]+=1
        for i in range(1,n+1):
            if id[i]==n-1 and od[i]==0:
                return i
        return -1