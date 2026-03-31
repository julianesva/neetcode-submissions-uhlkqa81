from collections import deque
class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:

        number_islands = 0

        for r in range(len(grid)): 
            for c in range(len(grid[0])): 
                if grid[r][c] == "1": 
                    grid[r][c] = "0"
                    number_islands+=1
                    q = deque()
                    dir = [(1,0), (-1,0), (0,1), (0,-1)]
                    q.append((r,c))

                    while(q):
                        row, col = q.popleft()

                        for dr, dc in dir: 
                            nrow = row + dr
                            ncol = col + dc
                            if nrow >= 0 and nrow < len(grid) and ncol >= 0 and ncol < len(grid[0]) and grid[nrow][ncol] == "1":
                                grid[nrow][ncol] = "0"
                                q.append((nrow,ncol))

        return number_islands
        