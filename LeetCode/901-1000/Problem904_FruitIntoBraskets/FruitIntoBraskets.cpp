class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int* count = new int[n];
        memset(count, 0, n * sizeof(int));

        int left = 0, right = 0, types = 0, maxFruits = 0;

        while (right < n) {
            if (count[fruits[right]] == 0) {
                types++;
            }
            count[fruits[right]]++;
            right++;

            while (types > 2) {
                count[fruits[left]]--;
                if (count[fruits[left]] == 0) {
                    types--;
                }
                left++;
            }

            int windowSize = right - left;
            if (windowSize > maxFruits) {
                maxFruits = windowSize;
            }
        }

        delete[] count;
        return maxFruits;
    }
};