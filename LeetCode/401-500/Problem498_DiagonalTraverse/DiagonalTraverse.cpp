class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> result;
        result.reserve(m * n);

        int row = 0, col = 0;
        bool up = true; 

        for (int i = 0; i < m * n; i++) {
            result.push_back(mat[row][col]);

            if (up) {
                if (col == n - 1) {   
                    row++;
                    up = false;
                } else if (row == 0) {
                    col++;
                    up = false;
                } else {
                    row--;
                    col++;
                }
            } else {
                if (row == m - 1) {   
                    col++;
                    up = true;
                } else if (col == 0) {
                    row++;
                    up = true;
                } else {
                    row++;
                    col--;
                }
            }
        }

        return result;
    }
};
