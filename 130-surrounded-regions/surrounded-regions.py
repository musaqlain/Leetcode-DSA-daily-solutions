class Solution:
    def solve(self, board: List[List[str]]) -> None:
        m = len(board)
        n = len(board[0])

        directions = [[0, 1], [1, 0], [0, -1], [-1, 0]]

        def dfs(r, c):
            # base
            # check if it is not out of bound
            if r <0 or r >= m or c <0 or c >= n or board[r][c] != 'O':
                return

            #  O -> E
            board[r][c] = "E"
            # loop directions
            for dr, dc in directions:
                nr, nc = dr+r, dc+c
                dfs(nr, nc)

        # loop on the borders
        # loop on column
        for c in range(n):
            dfs(0, c) # row = 0
            dfs(m-1, c) # row = m -1
        
        # loop on row
        for r in range(m):
            dfs(r, 0) # column = 0
            dfs(r, n-1) # column = n -1
            
        # iterate each element in board
        for i in range(m):
            for j in range(n):
                if board[i][j] == "O":
                    board[i][j] = "X"
                if board[i][j] == "E":
                    board[i][j] = "O"