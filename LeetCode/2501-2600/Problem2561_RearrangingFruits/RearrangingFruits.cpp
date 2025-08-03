class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        unordered_map<int, int> imbalance;
        int globalMin = INT_MAX;

        for (int x : basket1) {
            imbalance[x]++;
            globalMin = min(globalMin, x);
        }

        for (int x : basket2) {
            imbalance[x]--;
            globalMin = min(globalMin, x);
        }

        vector<int> toSwap;
        for (auto& [num, diff] : imbalance) {
            if (abs(diff) % 2 != 0) return -1;

            for (int i = 0; i < abs(diff) / 2; ++i)
                toSwap.push_back(num);
        }

        sort(toSwap.begin(), toSwap.end());

        long long cost = 0;
        int half = toSwap.size() / 2;
        for (int i = 0; i < half; ++i) {
            cost += min(toSwap[i], 2 * globalMin);
        }

        return cost;
    }
};
