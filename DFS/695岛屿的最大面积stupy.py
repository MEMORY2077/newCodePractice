from typing import List
class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        m=len(grid)
        n=len(grid[0])
        ans=0
        count=0
        visited=[[False]*n for _ in range(m)]
        def dfs(sx:int,sy:int):
            nonlocal count
            count+=1
            dir=[[0,1],[0,-1],[1,0],[-1,0]]
            for i in range(4):
                nx=sx+dir[i][0]
                ny=sy+dir[i][1]
                if nx>=0 and ny>=0 and nx<m and ny<n and not visited[nx][ny] and grid[nx][ny]==1:
                    visited[nx][ny]=True
                    dfs(nx,ny)
        for i in range(m):
            for j in range(n):
                if grid[i][j]==1 and not visited[i][j]:
                    visited[i][j]=True
                    count=0
                    dfs(i,j)
                    ans=max(ans,count)
        return ans