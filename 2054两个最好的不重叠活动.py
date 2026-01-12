from bisect import bisect_left
from typing import List
class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda e:e[1])
        st=[(0,0)]
        ans=0
        for start_time,end_time,value in events:
            i=bisect_left(st,(start_time,))-1
            ans=max(ans,st[i][1]+value)
            if value>st[-1][1]:
                st.append((end_time,value))
        return ans