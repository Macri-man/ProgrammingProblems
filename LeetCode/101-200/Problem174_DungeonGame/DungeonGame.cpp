class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size(), n = dungeon[0].size();
        vector<int> dp(n, INT_MAX);
        dp[n - 1] = max(1, 1 - dungeon[m - 1][n - 1]);

        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                if (i == m - 1 && j == n - 1) continue;
                int down = (i + 1 < m) ? dp[j] : INT_MAX;
                int right = (j + 1 < n) ? dp[j + 1] : INT_MAX;
                int need = min(down, right);
                dp[j] = max(1, need - dungeon[i][j]);
            }
        }

        return dp[0];
    }
};
