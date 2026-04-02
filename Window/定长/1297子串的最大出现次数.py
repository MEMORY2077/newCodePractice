# a,ab,abc长的会覆盖短的，所以不考虑大的，只考虑最短的
from typing import defaultdict
class Solution:
    def maxFreq(self, s: str, maxLetters: int, minSize: int, maxSize: int) -> int:
        cnt=defaultdict(int)
        lettercnt=defaultdict(int)
        n=len(s)
        res=''
        mm=0
        for i in range(0,n):
            res+=s[i]
            lettercnt[s[i]]+=1
            l=i-minSize+1
            if l < 0:
                continue
            cnt[res] += 1
            if len(lettercnt)<=maxLetters:
                mm = max(mm,cnt[res])
            res=res[1:]
            lettercnt[s[l]]-=1
            if lettercnt[s[l]] <=0:
                lettercnt.pop(s[l])
        return mm
        
            