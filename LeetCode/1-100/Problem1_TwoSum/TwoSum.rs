#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(const vector<int>& nums, int target) {
        unordered_map<int, int> num_map;
        num_map.reserve(nums.size());
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            auto it = num_map.find(complement);
            
            if (it != num_map.end()) {
                return {it->second, i};
            }
            
            num_map[nums[i]] = i;
        }
        
        return {};
    }
};