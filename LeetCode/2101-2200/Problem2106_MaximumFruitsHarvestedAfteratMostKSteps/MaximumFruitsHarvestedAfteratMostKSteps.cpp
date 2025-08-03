class Solution {
public:
    int maxTotalFruits(vector<vector<int>>& fruits, int startPos, int k) {
        int n = fruits.size();
        int i = 0; 
        int total = 0;
        int maxFruits = 0;

        for (int j = 0; j < n; ++j) {
            total += fruits[j][1];

            while (i <= j) {
                int left = fruits[i][0];
                int right = fruits[j][0];

                int leftFirst = abs(startPos - left) + (right - left);
                int rightFirst = abs(startPos - right) + (right - left);
                int steps = min(leftFirst, rightFirst);

                if (steps <= k) break;

                total -= fruits[i][1]; 
                ++i;
            }

            maxFruits = max(maxFruits, total);
        }

        return maxFruits;
    }
};
