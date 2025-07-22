#include <vector>
#include <algorithm>

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        int n = nums.size();
        if (n < 4) return result;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            long long min1 = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (min1 > target) break;  
            long long max1 = (long long)nums[i] + nums[n - 1] + nums[n - 2] + nums[n - 3];
            if (max1 < target) continue;  

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long min2 = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (min2 > target) break; 
                long long max2 = (long long)nums[i] + nums[j] + nums[n - 1] + nums[n - 2];
                if (max2 < target) continue;  
                int left = j + 1;
                int right = n - 1;

                while (left < right) {
                    long long sum = (long long)nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum == target) {
                        result.push_back({nums[i], nums[j], nums[left], nums[right]});
                        int left_val = nums[left];
                        int right_val = nums[right];
                        while (left < right && nums[left] == left_val) ++left;
                        while (left < right && nums[right] == right_val) --right;
                    } else if (sum < target) {
                        ++left;
                    } else {
                        --right;
                    }
                }
            }
        }

        return result;
    }
};
