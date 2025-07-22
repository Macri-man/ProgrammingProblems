#include <vector>

class Solution {
public:
    int maximumUniqueSubarray(std::vector<int>& nums) {
        std::vector<bool> exists(10001, false);

        int left = 0;
        int currentSum = 0;
        int maxSum = 0;

        for (int right = 0; right < nums.size(); ++right) {
            while (exists[nums[right]]) {
                exists[nums[left]] = false;
                currentSum -= nums[left];
                ++left;
            }

            exists[nums[right]] = true;
            currentSum += nums[right];
            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        return maxSum;
    }
};
