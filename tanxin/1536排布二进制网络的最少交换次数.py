class Solution:
    def minSwaps(self, grid: List[List[int]]) -> int:
        n=len(grid)
        #统计后导0
        lasZero=[n]*n
        for i in range(0,n):
            for j in range(n-1,-1,-1):
                if grid[i][j]:
                    lasZero[i]=n-j-1
                    break
        
        ans = 0
        for i in range(0,n-1):
            needZero=n-1-i
            for j in range(i,n):
                if lasZero[j] >= needZero:
                    ans += (j-i)
                    lasZero[i+1:j+1]=lasZero[i:j]
                    break
            else:
                return -1
        return ans
