from typing import List
from collections import deque

class Solution:
    def maxAreaOfIsland(self, grid: List[List[int]]) -> int:
        maxi = 0

        m, n = len(grid), len(grid[0])
        vis = [[0] * n for _ in range(m)]

        def bfs(row, col, grid, vis):
            vis[row][col] = 1

            q = deque([(row, col)])
            area = 1

            while q:
                row, col = q.popleft()
                directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]
                for dr, dc in directions:
                    nrow, ncol = row + dr, col + dc
                    if (0 <= nrow < m and 0 <= ncol < n and vis[nrow][ncol] == 0 and grid[nrow][ncol] == 1):
                        q.append((nrow, ncol))
                        vis[nrow][ncol] = 1
                        area += 1


            return area

        for row in range(m):
            for col in range(n):
                if (grid[row][col] == 1 and vis[row][col] == 0):
                    curr = bfs(row, col, grid, vis)
                    maxi = max(maxi, curr)
        
        return maxi