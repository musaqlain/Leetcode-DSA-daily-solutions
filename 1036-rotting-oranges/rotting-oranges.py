class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        direction = [[-1, 0], [0, -1], [1, 0], [0, 1]]

        queue = collections.deque()
        fresh = 0

        m, n = len(grid), len(grid[0])

        for i in range(m):
            for j in range(n):
                if grid[i][j] == 2:
                    queue.append((i, j))
                elif grid[i][j] == 1:
                    fresh += 1
        

        queue.append((-1, -1))
        minutes = -1

        while queue:
            curr_r, curr_c = queue.popleft()

            if curr_r == -1:
                minutes += 1

                if queue:
                    queue.append((-1, -1))
                    continue

            for dr in direction:
                new_r, new_c = dr[0] + curr_r, dr[1] + curr_c
                # if out of bound
                if new_r < 0 or new_r >= m or new_c < 0 or new_c >= n:
                    continue

                if grid[new_r][new_c] == 1:
                    grid[new_r][new_c] = 2
                    fresh -= 1
                    queue.append((new_r, new_c))

        if fresh == 0:
            return minutes
        return -1