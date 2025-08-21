class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;
        long long streak = 0;
        for (int n : nums) {
            if (n == 0) {
                streak++;
            } else {
                if (streak > 0) {
                    count += streak * (streak + 1) / 2;
                    streak = 0;
                }
            }
        }
        if (streak > 0) count += streak * (streak + 1) / 2;
        return count;
    }
};
