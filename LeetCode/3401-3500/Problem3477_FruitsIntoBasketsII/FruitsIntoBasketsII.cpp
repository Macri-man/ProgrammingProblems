class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size();
        bool used[100] = {false};
        int unplaced = 0;

        int prefix_max[100];
        prefix_max[n - 1] = baskets[n - 1];
        for (int i = n - 2; i >= 0; --i) {
            prefix_max[i] = std::max(baskets[i], prefix_max[i + 1]);
        }

        for (int i = 0; i < n; ++i) {
            int fruit = fruits[i];

            if (prefix_max[0] < fruit) {
                ++unplaced;
                continue;
            }

            bool placed = false;
            for (int j = 0; j < n; ++j) {
                if (!used[j] && baskets[j] >= fruit) {
                    used[j] = true;
                    placed = true;
                    break;
                }
            }

            if (!placed) ++unplaced;
        }

        return unplaced;
    }
};
