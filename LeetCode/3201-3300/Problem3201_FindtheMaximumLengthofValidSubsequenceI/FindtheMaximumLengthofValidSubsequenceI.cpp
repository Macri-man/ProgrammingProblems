class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int evenCount = 0, oddCount = 0;
        for (int x : nums) {
            if (x % 2 == 0) evenCount++;
            else oddCount++;
        }
        int maxSameParity = std::max(evenCount, oddCount);

        int maxAlternating = 1;
        int prevParity = nums[0] % 2;

        for (int i = 1; i < n; ++i) {
            int curParity = nums[i] % 2;
            if (curParity != prevParity) {
                maxAlternating++;
                prevParity = curParity;
            }
        }

        return std::max(maxSameParity, maxAlternating);
    }
};
