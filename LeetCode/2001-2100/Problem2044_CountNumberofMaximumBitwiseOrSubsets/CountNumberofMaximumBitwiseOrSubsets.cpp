class Solution {
public:
    int max_or = 0, count = 0;
    void dfs(const vector<int>& nums, int index, int current_or) {
        if (index == nums.size()) {
            if (current_or == max_or) count++;
            return;
        }

        dfs(nums, index + 1, current_or | nums[index]);
        dfs(nums, index + 1, current_or);
    }

    int countMaxOrSubsets(vector<int>& nums) {
        for (int num : nums) max_or |= num;

        dfs(nums, 0, 0);
        return count;
    }
};
