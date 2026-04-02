class Solution:
    def minimumRecolors(self, blocks: str, k: int) -> int:
        ans = 101
        s=0
        n=len(blocks)
        for i in range(n):
            s +=1 if blocks[i]=='W' else 0
            l = i-k+1
            if l <0:
                continue
            ans = min(ans,s)
            s -= 1 if blocks[l]=='W' else 0
        return ans
            