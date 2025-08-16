class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int numberOfWays(int n, int x) {
        std::vector<int> powers;
        for (int i = 1;; ++i) {
            int val = 1;
            for (int j = 0; j < x; ++j) {
                val *= i;
                if (val > n) break; 
            }
            if (val > n) break;
            powers.push_back(val);
        }

        std::vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : powers) {
            for (int j = n; j >= p; --j) {
                dp[j] = (dp[j] + dp[j - p]) % MOD;
            }
        }

        return dp[n];
    }
};
