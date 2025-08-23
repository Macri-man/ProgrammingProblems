#include <bitset>

class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<bitset<1000>> rows(m);
        bitset<1000> mergedCols; 

        int minRow = m, maxRow = -1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    rows[i].set(j);
                }
            }
            if (rows[i].any()) {  
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);
            }
            mergedCols |= rows[i];
        }

        int minCol = n, maxCol = -1;

        for (int j = 0; j < n; j++) {
            if (mergedCols.test(j)) {
                minCol = j;
                break;
            }
        }
        for (int j = n - 1; j >= 0; j--) {
            if (mergedCols.test(j)) {
                maxCol = j;
                break;
            }
        }

        int height = maxRow - minRow + 1;
        int width  = maxCol - minCol + 1;

        return height * width;
    }
};
