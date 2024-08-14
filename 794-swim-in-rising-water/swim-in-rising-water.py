import heapq

class Solution:
    def swimInWater(self, grid: List[List[int]]) -> int:
        row, col = len(grid), len(grid[0])
        # direction
        direction = [[0, 1], [1, 0], [0, -1], [-1, 0], ]
        # priority-q
        minH = [[grid[0][0], 0, 0]] # r, c, time

        # visited
        vis = set()
        vis.add((0, 0))

        # while loop
        while minH:
            t, r, c = heapq.heappop(minH)

            if r == row-1 and c == col-1:
                return t

            for dr, dc in direction:
                newR, newC = r+dr, c+dc

                # check if it outof bound
                if (newR < 0 or newR == row or 
                    newC < 0 or newC == col or
                    (newR, newC) in vis):
                    continue

                vis.add((newR, newC))
                heapq.heappush(minH, [ max(t, grid[newR][newC]), newR, newC])

        