from collections import deque
class Solution:
    def nearestExit(self, maze: List[List[str]], entrance: List[int]) -> int:
        q = deque()
        q.append((entrance[0], entrance[1], 0))
        directions = [(1,0), (0,1), (-1, 0), (0, -1)]
        rows, cols = len(maze), len(maze[0])

        while q:
            # check if the current cell is at edge (base condition)

            # move in 4 directions
            row, col, steps = q.popleft()

            for shift_r, shift_c in directions:
                new_r, new_c = row+shift_r, col+shift_c
                # add checks here

                if 0 <= new_r < rows and 0 <= new_c < cols and maze[new_r][new_c] == '.':
                    if (new_r==0 or new_r==rows-1 or new_c==0 or new_c==cols-1) and [new_r, new_c] != entrance: # means it is at border
                        return steps+1
  
                    q.append((new_r, new_c, steps+1))
                    maze[new_r][new_c] = '+'

        return -1
