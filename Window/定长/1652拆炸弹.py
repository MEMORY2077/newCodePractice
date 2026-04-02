class Solution:
    def decrypt(self, code: List[int], k: int) -> List[int]:
        inin=len(code)
        code = code * 2
        res = 0
        ans = [0]*inin
        if k == 0:
            return ans
        if(k>0):
            for i in range(0,inin+k):
                res+=code[i]
                l = i-k+1
                if l<0:
                    continue
                if l>0:
                    ans[l-1]=res
                res-=code[l]
        else:
            k=-k
            for i in range(0,2*inin):
                res+=code[i]
                l = i-k+1
                if l < 0:
                    continue
                ans[(i+1)%inin]=res
                res-=code[l]
        return ans