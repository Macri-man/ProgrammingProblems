class Solution {
public:
    int longestSubarray(std::vector<int>& nums) {
        int max_val = 0;
        int longest = 0;
        int current_length = 0;
        
        for (int num : nums) {
            if (num > max_val) {
                max_val = num;
                current_length = 1;
                longest = 1;
            } else if (num == max_val) {
                current_length++;
                if (current_length > longest) {
                    longest = current_length;
                }
            } else {
                current_length = 0;
            }
        }
        
        return longest;
    }
};
