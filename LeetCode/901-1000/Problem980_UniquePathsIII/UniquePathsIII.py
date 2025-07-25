class Solution:
    def uniquePathsIII(self, grid):
        self.rows, self.cols = len(grid), len(grid[0])
        self.result = 0
        total = 0
        startX = startY = 0
        
        for i in range(self.rows):
            for j in range(self.cols):
                if grid[i][j] != -1:
                    total += 1
                if grid[i][j] == 1:
                    startX, startY = i, j
        
        def dfs(x, y, remain):
            
            if x < 0 or x >= self.rows or y < 0 or y >= self.cols or grid[x][y] == -1:
                return
            if grid[x][y] == 2:
                if remain == 0:
                    self.result += 1
                return
            
            temp = grid[x][y]
            grid[x][y] = -1
            remain -= 1
            
            dfs(x + 1, y, remain)
            dfs(x - 1, y, remain)
            dfs(x, y + 1, remain)
            dfs(x, y - 1, remain)
            
            grid[x][y] = temp
        
        dfs(startX, startY, total - 1)
        return self.result
