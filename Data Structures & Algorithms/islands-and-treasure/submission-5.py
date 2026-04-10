class Solution:
    def bfsTreasureDist(self, grid: List[List[int]], visit: List[List[int]], q: deque) -> None:
        INT_MAX = 2**31 - 1
        rows = len(grid)
        cols = len(grid[0])
        dir = [(1,0),(-1,0),(0,1),(0,-1)]
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
                        if not visit[dr][dc] and grid[dr][dc] == INT_MAX:
                            visit[dr][dc] = True
                            q.append((dr,dc))
                            grid[dr][dc] = distance
        
    def islandsAndTreasure(self, grid: List[List[int]]) -> None:
        INT_MAX = 2**31 - 1
        rows = len(grid)
        cols = len(grid[0])
        q = deque()
        visit = [[False] * cols for _ in range(rows)]

        for r in range(rows):
            for c in range(cols): 
                if grid[r][c] == 0:
                    q.append((r,c))
                    visit[r][c] = True
        
        self.bfsTreasureDist(grid, visit, q)
        


        