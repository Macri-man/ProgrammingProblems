class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n, -1);

        function<int(int)> dfs = [&](int i) -> int {
            if (dp[i] != -1) return dp[i];
            int res = 1;

            for (int j = i + 1; j <= i + d && j < n; ++j) {
                if (arr[j] >= arr[i]) break; 
                res = max(res, 1 + dfs(j));
            }

            for (int j = i - 1; j >= i - d && j >= 0; --j) {
                if (arr[j] >= arr[i]) break;
                res = max(res, 1 + dfs(j));
            }

            return dp[i] = res;
        };

        int result = 1;
        for (int i = 0; i < n; ++i) {
            result = max(result, dfs(i));
        }

        return result;
    }
};