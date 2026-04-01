class Solution:

    def dfs(self, heights, prev, r, c, visited): 
        if (r < 0 or r >= len(heights) or c < 0 or c >= len(heights[0]) or heights[r][c] < prev or (r, c) in visited):
            return
        
        visited.add((r,c))

        self.dfs(heights, heights[r][c], r+1, c, visited)
        self.dfs(heights, heights[r][c], r-1, c, visited)
        self.dfs(heights, heights[r][c], r, c+1, visited)
        self.dfs(heights, heights[r][c], r, c-1, visited)

    def pacificAtlantic(self, heights: List[List[int]]) -> List[List[int]]:

        result = []
        rows, cols = len(heights), len(heights[0])
        pacific, atlantic = set(), set()

        for c in range(cols):
            self.dfs(heights, heights[0][c], 0, c, pacific)
            self.dfs(heights, heights[rows-1][c], rows-1, c, atlantic)

        for r in range(rows):
            self.dfs(heights, heights[r][0], r, 0, pacific)
            self.dfs(heights, heights[r][cols-1], r, cols-1, atlantic)

        for row in range(rows):
            for col in range(cols):
                if((row,col) in atlantic and (row,col) in pacific):
                    result.append([row,col])

        return result
        