class Solution {
public:
    inline bool canRob(const vector<int>& nums, int k, int cap) {
        int n = nums.size(), count = 0;
        for (int i = 0; i < n;) {
            if (nums[i] <= cap) {
                count++;
                i += 2;
            } else {
                i++;
            }
            if (count >= k) return true;  
        }
        return false;
    }

    int minCapability(vector<int>& nums, int k) {
        int lo = nums[0], hi = nums[0];
        for (int v : nums) {
            if (v < lo) lo = v;
            else if (v > hi) hi = v;
        }

        int res = hi;
        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (canRob(nums, k, mid)) {
                res = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return res;
    }
};
