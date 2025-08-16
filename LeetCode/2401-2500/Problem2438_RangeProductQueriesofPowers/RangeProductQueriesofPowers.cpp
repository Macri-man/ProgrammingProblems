
class Solution {
    static constexpr int MOD = 1'000'000'007;

public:
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> exps;
        exps.reserve(31);

        unsigned int x = (unsigned int)n;
        for (int bit = 0; bit < 31; ++bit) {
            if ((x & (1U << bit)) != 0) {
                exps.push_back(bit);
            }
        }

        int k = (int)exps.size();
        vector<int> prefix(k + 1, 0);
        for (int i = 0; i < k; ++i) {
            prefix[i + 1] = prefix[i] + exps[i];
        }

        int max_exp = prefix[k];
        vector<int> pow2(max_exp + 1, 1);
        for (int i = 1; i <= max_exp; ++i) {
            pow2[i] = (int)((2LL * pow2[i - 1]) % MOD);
        }

        int qsz = (int)queries.size();
        vector<int> ans(qsz);
        for (int i = 0; i < qsz; ++i) {
            int l = queries[i][0], r = queries[i][1];
            int sum_exp = prefix[r + 1] - prefix[l];
            ans[i] = pow2[sum_exp];
        }
        return ans;
    }
};