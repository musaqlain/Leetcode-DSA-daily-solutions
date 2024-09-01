class Solution:
    def longestIncreasingPath(self, matrix: List[List[int]]) -> int:
        longest_path = 0
        rows, cols = len(matrix), len(matrix[0])
        direction = [[1, 0], [0, 1], [-1, 0], [0, -1]]

        # 1
        memory = [[-1] * cols for _ in range(rows)]

        def dfs(i, j): # 0, 1
            # 2
            if memory[i][j] != -1:
                # return <-- alteady calculated
                return memory[i][j]


            max_len = 1

            # explore all the possible ways
            for dr, dc in direction:
                new_r, new_c = i+dr, j+dc
                if new_r >= 0 and new_r < rows and new_c >= 0 and new_c < cols and matrix[i][j] < matrix[new_r][new_c]:
                    max_len = max(max_len, 1 + dfs(new_r, new_c))

            # 3
            memory[i][j] = max_len
            return max_len
        
        for i in range(rows):
            for j in range(cols):
                # dfs()
                 # row, col, prev
                 longest_path = max(longest_path, dfs(i, j))



        return longest_path
        