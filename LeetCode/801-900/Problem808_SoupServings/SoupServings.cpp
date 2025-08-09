class Solution {
    static constexpr int CUTOFF = 200;
    static constexpr double EPS = 1e-9;
    static constexpr int pours[4][2] = {
        {4, 0},
        {3, 1},
        {2, 2},
        {1, 3}
    };

public:
    double soupServings(int n) {
        if (n == 0) return 0.5;
        int scaledN = (n + 24) / 25;
        if (scaledN >= CUTOFF) return 1.0;

        int maxN = min(scaledN, CUTOFF);
        vector<vector<double>> dp(maxN + 1, vector<double>(maxN + 1, 0.0));

        dp[0][0] = 0.5;
        for (int b = 1; b <= maxN; ++b) dp[0][b] = 1.0;
        for (int a = 1; a <= maxN; ++a) dp[a][0] = 0.0;

        for (int a = 1; a <= maxN; ++a) {
            for (int b = 1; b <= maxN; ++b) {
                if (a >= CUTOFF && b >= CUTOFF) {
                    dp[a][b] = 1.0;
                    continue;
                }

                double res = 0.0;
                for (int i = 0; i < 4; ++i) {
                    int na = max(a - pours[i][0], 0);
                    int nb = max(b - pours[i][1], 0);
                    res += dp[na][nb];
                }
                dp[a][b] = res * 0.25;

                if (dp[a][b] > 1.0 - EPS) dp[a][b] = 1.0; 
            }
        }

        return dp[scaledN][scaledN];
    }
};
