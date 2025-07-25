
class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> seen;
        int positiveSum = 0;
        int maxNum = nums[0];  

        for (int num : nums) {
            maxNum = max(maxNum, num);
            if (num > 0 && seen.find(num) == seen.end()) {
                positiveSum += num;
                seen.insert(num);
            }
        }

        if (positiveSum == 0) {
            return maxNum;
        }

        return positiveSum;
    }
};