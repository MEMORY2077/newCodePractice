from typing import List
class Solution:
    def minimumBoxes(self, apple: List[int], capacity: List[int]) -> int:
        capacity.sort(reverse=True)
        coa=0
        for now in apple:
            coa+=now
        ans=0
        for cap in capacity:
            ans+=1
            coa-=cap
            if coa<=0:
                break
        return ans