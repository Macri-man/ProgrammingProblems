#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        const double EPS = 1e-6;
        unordered_map<string, bool> memo;

        function<string(const vector<double>&)> makeKey = [&](const vector<double>& nums) {
            vector<int> scaled;
            for (double x : nums) scaled.push_back((int)round(x * 1000));
            sort(scaled.begin(), scaled.end());
            string k;
            for (int v : scaled) k += to_string(v) + ",";
            return k;
        };

        function<bool(vector<double>&)> dfs = [&](vector<double>& nums) -> bool {
            if (nums.size() == 1) return fabs(nums[0] - 24.0) < EPS;

            string k = makeKey(nums);
            if (memo.count(k)) return memo[k];

            int n = nums.size();
            for (int i = 0; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    vector<double> rest;
                    for (int k = 0; k < n; k++) {
                        if (k != i && k != j) rest.push_back(nums[k]);
                    }

                    double a = nums[i], b = nums[j];
                    vector<double> candidates = {a + b, a - b, b - a, a * b};
                    if (fabs(b) > EPS) candidates.push_back(a / b);
                    if (fabs(a) > EPS) candidates.push_back(b / a);

                    for (double val : candidates) {
                        rest.push_back(val);
                        if (dfs(rest)) return memo[k] = true;
                        rest.pop_back();
                    }
                }
            }
            return memo[k] = false;
        };

        vector<double> nums;
        for (int x : cards) nums.push_back((double)x);
        return dfs(nums);
    }
};
