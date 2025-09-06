class Solution {
public:
    long long minOperations(vector<vector<int>>& queries) {
        long long total = 0;
        vector<long long> pow4(16, 1);
        for (int i = 1; i <= 15; ++i) {
            pow4[i] = pow4[i-1] * 4;
        }
        
        for (const auto& query : queries) {
            int l = query[0], r = query[1];
            long long sum_steps = 0;
            for (int k = 1; k <= 15; ++k) {
                long long L = pow4[k-1];
                long long R = pow4[k] - 1;
                if (R < l || L > r) continue;
                long long overlap_l = max(l, (int)L);
                long long overlap_r = min(r, (int)R);
                sum_steps += (overlap_r - overlap_l + 1) * k;
            }
            total += (sum_steps + 1) / 2;
        }
        return total;
    }
};