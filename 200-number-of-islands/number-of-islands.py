class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        m = len(grid)
        n = len(grid[0])
        count = 0

        # create a 2D Array
        vis = [[0]* n for _ in range(m)]

        # define bfs function
        def bfs(row, col, grid, vis):
            vis[row][col] = 1
            # initialize queue
            q = deque()
            q.append((row, col))

            while q:
                row, col = q.popleft()

                directions = [(-1, 0), (1, 0), (0, -1), (0, 1)]

                for dr, dc in directions:
                    nrow = row + dr
                    ncol = col + dc
                    
                    if 0 <= nrow < m and 0 <= ncol < n and grid[nrow][ncol] == '1' and not vis[nrow][ncol]:
                        vis[nrow][ncol] = 1
                        q.append((nrow, ncol))

        for row in range(m):
            for col in range(n):
                if (grid[row][col] == '1' and vis[row][col] != 1):
                    count += 1
                    bfs(row, col, grid, vis)
        

        return count