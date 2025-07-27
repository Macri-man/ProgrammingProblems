
class Solution {
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs) {
        for (auto& p : conflictingPairs) {
            if (p[0] > p[1]) swap(p[0], p[1]);
        }

        vector<vector<int>> conflict_by_b(n + 1);
        for (auto& p : conflictingPairs) {
            conflict_by_b[p[1]].push_back(p[0]);
        }

        long long ans = 0;
        unordered_map<int, long long> bonus;

        priority_queue<int> active;
        unordered_map<int, int> count_map;

        int top1 = 0, top2 = 0;

        for (int r = 1; r <= n; ++r) {
            for (int a : conflict_by_b[r]) {
                active.push(a);
                count_map[a]++;
            }

            while (!active.empty() && count_map[active.top()] == 0) {
                active.pop();
            }

            if (active.empty()) {
                top1 = 0;
                top2 = 0;
            } else {
                top1 = active.top();
                count_map[top1]--;
                active.pop();

                if (active.empty()) {
                    top2 = 0;
                } else {
                    top2 = active.top();
                }

                active.push(top1);
                count_map[top1]++;
            }

            long long valid_count = r - top1;
            if (valid_count < 0) valid_count = 0;
            ans += valid_count;

            long long gain = top1 - top2;
            if (gain > 0) {
                bonus[top1] += gain;
            }
        }

        long long max_bonus = 0;
        for (auto& [key, val] : bonus) {
            if (val > max_bonus) max_bonus = val;
        }

        return ans + max_bonus;
    }
};