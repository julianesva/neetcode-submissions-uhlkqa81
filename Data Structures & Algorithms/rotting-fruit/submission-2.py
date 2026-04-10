class Solution:
    def bfsSearchFFruit(self, q: deque,  grid: List[List[int]], visit: List[List[int]]) -> int:
        directions = [(1,0),(-1,0),(0,1),(0,-1)]
        minutes = 0
        while q: 
            size = len(q)
            for _ in range(size): 
                r, c = q.popleft()
                for x, y in directions:
                    dr = r + x
                    dc = c + y
                    if dr >= 0 and dr < len(grid) and dc >= 0 and dc < len(grid[0]) and not visit[dr][dc] and grid[dr][dc] == 1:
                        q.append((dr,dc))
                        visit[dr][dc] = True 
            if q: 
                minutes += 1
        if minutes == 0: 
            return -1

        return minutes

    def orangesRotting(self, grid: List[List[int]]) -> int:

        q = deque()
        rows = len(grid)
        cols = len(grid[0])
        visit = [[False] * cols for _ in range(rows)]
        fruit = 0

        for r in range(rows):
            for c in range(cols): 
                if grid[r][c] == 1: 
                    fruit +=1
                elif grid[r][c] == 2:
                    q.append((r,c))
                    visit[r][c] = True
        if fruit == 0: 
            return 0
        res_minutes = self.bfsSearchFFruit(q, grid, visit)

        for r in range(rows):
            for c in range(cols): 
                if grid[r][c] == 1 and not visit[r][c]: 
                    return -1

        return res_minutes

        

        