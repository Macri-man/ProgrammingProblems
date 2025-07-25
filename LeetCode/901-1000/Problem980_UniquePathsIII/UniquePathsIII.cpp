class Solution {
public:
    int rows, cols, total;
    int startX, startY;
    int result = 0;

    void dfs(vector<vector<int>>& grid, int x, int y, int remain) {
        if (x < 0 || x >= rows || y < 0 || y >= cols || grid[x][y] == -1)
            return;
        if (grid[x][y] == 2) {
            if (remain == 0) result++;
            return;
        }
        int temp = grid[x][y];
        grid[x][y] = -1;
        remain--;
        dfs(grid, x + 1, y, remain);
        dfs(grid, x - 1, y, remain);
        dfs(grid, x, y + 1, remain);
        dfs(grid, x, y - 1, remain);
        grid[x][y] = temp;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        rows = grid.size();
        cols = grid[0].size();
        total = 0;
        for (int i = 0; i < rows; ++i)
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] != -1)
                    total++;
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
            }
        dfs(grid, startX, startY, total - 1);
        return result;
    }
};
