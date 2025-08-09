class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        int n = fruits.size();

        vector<vector<int>> dp2(2, vector<int>(n, -1)); 
        vector<vector<int>> dp3(2, vector<int>(n, -1)); 

        dp2[0][n - 1] = fruits[0][n - 1];
        dp3[0][n - 1] = fruits[n - 1][0];

        int diagSum = 0;

        for (int step = 0; step < n; ++step) {
            int curr = step % 2;
            int prev = 1 - curr;

            diagSum += fruits[step][step];
            fruits[step][step] = 0;

            if (step == 0) continue;

            for (int j = 0; j < n; ++j) {
                int best = -1;
                if (j > 0 && dp2[prev][j - 1] != -1)
                    best = max(best, dp2[prev][j - 1]);
                if (dp2[prev][j] != -1)
                    best = max(best, dp2[prev][j]);
                if (j + 1 < n && dp2[prev][j + 1] != -1)
                    best = max(best, dp2[prev][j + 1]);
                dp2[curr][j] = (best == -1 ? -1 : best + fruits[step][j]);
            }

            for (int i = 0; i < n; ++i) {
                int best = -1;
                if (i > 0 && dp3[prev][i - 1] != -1)
                    best = max(best, dp3[prev][i - 1]);
                if (dp3[prev][i] != -1)
                    best = max(best, dp3[prev][i]);
                if (i + 1 < n && dp3[prev][i + 1] != -1)
                    best = max(best, dp3[prev][i + 1]);
                dp3[curr][i] = (best == -1 ? -1 : best + fruits[i][step]);
            }
        }

        int child2 = dp2[(n - 1) % 2][n - 1];
        int child3 = dp3[(n - 1) % 2][n - 1];

        if (child2 == -1 || child3 == -1) return 0;

        int total = diagSum + child2 + child3 - fruits[n - 1][n - 1];
        return total;
    }
};
