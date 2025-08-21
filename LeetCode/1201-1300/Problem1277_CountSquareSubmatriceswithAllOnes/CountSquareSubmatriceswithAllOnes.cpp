class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> dp(n, 0);
        int total = 0, prev = 0;  

        for (int i = 0; i < m; i++) {
            prev = 0; 
            for (int j = 0; j < n; j++) {
                int temp = dp[j]; 
                if (matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[j] = 1;
                    } else {
                        dp[j] = min({dp[j], dp[j-1], prev}) + 1;
                    }
                    total += dp[j];
                } else {
                    dp[j] = 0;
                }
                prev = temp; 
            }
        }
        return total;
    }
};
