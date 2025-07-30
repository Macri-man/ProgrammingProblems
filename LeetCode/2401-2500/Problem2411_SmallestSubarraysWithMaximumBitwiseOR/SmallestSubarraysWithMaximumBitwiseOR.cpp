class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n);
        vector<int> lastSeenBit(30, -1);  

        for (int i = n - 1; i >= 0; --i) {
            for (int bit = 0; bit < 30; ++bit) {
                if ((nums[i] >> bit) & 1) {
                    lastSeenBit[bit] = i;
                }
            }

            int maxReach = i;
            for (int bit = 0; bit < 30; ++bit) {
                if (lastSeenBit[bit] != -1) {
                    maxReach = max(maxReach, lastSeenBit[bit]);
                }
            }

            answer[i] = maxReach - i + 1;
        }

        return answer;
    }
};
