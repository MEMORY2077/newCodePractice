from typing import List
class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        grid = [['.' for _ in range(n)] for _ in range(n)]
        ans=[]
        def feasible(n:int,now:int,line:int) -> bool:
            for i in range(0,now):
                if grid[i][line] == 'Q':
                    return False
            i = 1
            while now - i >=0 and line - i >=0:
                if grid[now - i][line - i] == 'Q':
                    return False
                i += 1
            i = 1
            while now - i >=0 and line + i <n:
                if grid[now - i][line + i] =='Q':
                    return False
                i += 1
            return True
        def Nqueens(n,now):
            if now == n:
                nonlocal ans
                ans.append([''.join(row) for row in grid])
                return
            for i in range(0,n):
                grid[now][i]='Q'
                if(feasible(n,now,i)):
                    Nqueens(n,now+1)
                grid[now][i]='.'
            return 
        Nqueens(n,0)
        return ans