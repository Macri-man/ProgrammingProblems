#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int possibleStringCount(string word, int k) {
        const int mod = 1'000'000'007;
        int n = (int)word.size();

        // Step 1: Group runs of characters
        vector<int> groups;
        int count = 1;
        for (int i = 1; i < n; i++) {
            if (word[i] == word[i - 1]) count++;
            else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);

        int m = (int)groups.size();

        // Step 2: Compute total ways = product of run lengths
        long long totalWays = 1;
        for (int x : groups) {
            totalWays = (totalWays * x) % mod;
        }

        // If minimal length (m) >= k, all ways count
        if (m >= k) return (int)totalWays;

        int maxLen = k - 1;  // count strings with length < k

        // DP initialization
        vector<int> dp(maxLen + 1, 0);
        dp[0] = 1;  // zero groups chosen -> length 0

        for (int i = 0; i < m; i++) {
            vector<int> new_dp(maxLen + 1, 0);
            vector<int> diff(maxLen + 2, 0);

            int r = groups[i];
            for (int length = 0; length <= maxLen; length++) {
                int start = length + 1;
                int end = length + r;
                if (start > maxLen) continue;
                if (end > maxLen) end = maxLen;

                diff[start] = (diff[start] + dp[length]) % mod;
                if (end + 1 <= maxLen) {
                    diff[end + 1] = (diff[end + 1] - dp[length] + mod) % mod;
                }
            }

            int running = 0;
            for (int pos = 0; pos <= maxLen; pos++) {
                running = (running + diff[pos]) % mod;
                new_dp[pos] = running;
            }

            dp = move(new_dp);
        }

        // sum dp[length] for length < k and length >= m (minimal length)
        long long lessThanK = 0;
        for (int length = m; length <= maxLen; length++) {
            lessThanK += dp[length];
            if (lessThanK >= mod) lessThanK -= mod;
        }

        // result = totalWays - lessThanK (mod)
        int ans = (int)(totalWays - lessThanK);
        if (ans < 0) ans += mod;

        return ans;
    }
};