class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        # create 2D rec
        rec = [[0]*n for _ in range(m)]

        # last row and last col -> 1
        for r in range(m):
            rec[r][n-1] = 1
        for c in range(n):
            rec[m-1][c] = 1

        # loop from last to first
            # and calculate total num of ways
        for i in range(m-2, -1, -1): # row
            for j in range(n-2, -1, -1): # col
                rec[i][j] = rec[i+1][j] + rec[i][j+1]

        return rec[0][0]