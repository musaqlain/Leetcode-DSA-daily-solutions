class Solution:
    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:
        # array for 4-directions
        direction = [[0, 1], [1, 0], [0, -1], [-1, 0]]
        ans = []

        r = len(heights)
        c = len(heights[0])

        atlantic = [[False] * c for _ in range(r)]
        pacific = [[False] * c for _ in range(r)]

        def dfs(i, j, prev, ocean):
            # no chance for out of bound
            if i < 0 or i >= r or j < 0 or j >= c:
                return
            
            # no chace for small values
            if prev > heights[i][j] or ocean[i][j]:
                return

            ocean[i][j] = True
            for dr, dc in direction:
                dfs(i+dr, j+dc, heights[i][j], ocean)


        # call dfs for first and last rows
        for i in range(c):
            dfs(0, i, -sys.maxsize - 1, pacific) # row = 0
            dfs(r-1, i, -sys.maxsize - 1, atlantic) # row = r-1
        # call dfs for first and last col
        for i in range(r):
            dfs(i, 0, -sys.maxsize - 1, pacific) # col = 0
            dfs(i, c-1, -sys.maxsize - 1, atlantic) # col = c-1        

        for i in range(r):
            for j in range(c):
                if pacific[i][j] and atlantic[i][j]:
                    ans.append([i,j])

        return ans