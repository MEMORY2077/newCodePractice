from typing import List
class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        group=[0]
        now=0
        nowc=''
        n=len(neededTime)
        ans=0
        for i in range(0,n):
            if colors[i]!=nowc:
                if len(group)!=1:
                    ans+=sum(group)-max(group)
                nowc=colors[i]
                group=[neededTime[i]]
            else :
                group.append(neededTime[i])
        if len(group)!=1:
            ans+=sum(group)-max(group)         
        return ans