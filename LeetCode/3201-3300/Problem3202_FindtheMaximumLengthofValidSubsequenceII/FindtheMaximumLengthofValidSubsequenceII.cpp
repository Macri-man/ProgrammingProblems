class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        int n = nums.size();
        int maxLen = 1;

        for (int modTarget = 0; modTarget < k; ++modTarget) {
            array<int, 1000> dp{};  
            for (int i = 0; i < n; ++i) {
                int modVal = nums[i] % k;
                int need = (modTarget - modVal + k) % k;
                int prev = dp[need];
                dp[modVal] = max(dp[modVal], prev + 1);
                maxLen = max(maxLen, dp[modVal]);
            }
        }

        return maxLen;
    }
};
