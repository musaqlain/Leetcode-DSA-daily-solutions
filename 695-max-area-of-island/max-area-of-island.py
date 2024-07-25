from typing import List
from collections import deque

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        max_area = 0

        m, n = len(grid), len(grid[0])

        def dfs(row, col, grid):
            # base condition
            if (0 > row or row >= m or 0 > col or col >= n or grid[row][col] == 0):
                return 0
            grid[row][col] = 0
            area = 1

            area += dfs(row-1, col, grid)
            area += dfs(row, col-1, grid)
            area += dfs(row+1, col, grid)
            area += dfs(row, col+1, grid)

            return area

        for row in range(m):
            for col in range(n):
                if (grid[row][col] == 1):
                    curr = dfs(row, col, grid)
                    max_area = max(max_area, curr)
        
        return max_area