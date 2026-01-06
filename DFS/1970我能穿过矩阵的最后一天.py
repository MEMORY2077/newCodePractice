from typing import List
class Solution:
    def latestDayToCross(self, row: int, col: int, cells: List[List[int]]) -> int:
        DIRS=[(0,-1),(0,1),(-1,0),(1,0)]
        state=[[0]*col for _ in range(row)]
        
        def can_reach_from_top(r:int, c: int)-> bool :# 能否到顶部
            if r ==0:
                return True
            for dx,dy in DIRS:
                x=r+dx
                y=c+dy
                if 0 <= x < row and 0 <= y < col and state[x][y]==2:
                    return True
            return False

        def dfs(r: int, c: int)-> bool:# 能否到底部
            if r == row - 1:
                return True
            state[r][c] = 2
            for dx,dy in DIRS:
                x, y = r + dx, c + dy
                if 0<= x <row and 0 <= y <col and state[x][y] == 1 and dfs(x,y):
                    return True
            return False

        for day in range(len(cells) - 1, -1, -1):
            r, c = cells[day]
            r-=1
            c-=1
            state[r][c] = 1 # 变成陆地
            if can_reach_from_top(r, c) and dfs(r, c):
                return day