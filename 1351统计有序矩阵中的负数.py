from typing import List
#O(mn):直接全都扫一遍
#O(mlogn):一维二分查找
#O(m+n):?bfs???
#看右上角，<0撕去当前列并计数，>=0撕去当前行
class Solution:
    def countNegatives(self, grid: List[List[int]]) -> int:
        m = len(grid)
        n = len(grid[0])
        ans = 0
        i = 0
        j = n - 1
        while i < m and j >= 0:
            if grid[i][j] < 0:#当前列全是负数
                ans += m - i
                j -= 1
            else:
                i += 1
        return ans