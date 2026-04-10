class Solution:
    def bfsTreasureDist(self, grid: List[List[int]], r: int, c: int) -> int:
        INT_MAX = 2**31 - 1
        rows = len(grid)
        cols = len(grid[0])
        visit = [[False] * cols for _ in range(rows)]
        dir = [(1,0),(-1,0),(0,1),(0,-1)]
        q = deque()
        q.append((r,c))
        visit[r][c] = True
        distance = 0

        while q:
            qsize = len(q)
            distance+=1
            for _ in range(qsize):
                r, c = q.popleft()
                for x, y in dir:
                    dr = r + x
                    dc = c + y
                    if dr >= 0 and dr < rows and dc >= 0 and dc < cols:
                        if grid[dr][dc] == 0:
                            return distance
                        elif grid[dr][dc] == -1: 
                            continue
                        elif not visit[dr][dc]:
                            visit[dr][dc] = True
                            q.append((dr,dc))
        return INT_MAX
        
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INT_MAX = 2**31 - 1
        rows = len(grid)
        cols = len(grid[0])

        for r in range(rows):
            for c in range(cols): 
                if grid[r][c] == INT_MAX:
                    grid[r][c] = self.bfsTreasureDist(grid, r, c)
        


        