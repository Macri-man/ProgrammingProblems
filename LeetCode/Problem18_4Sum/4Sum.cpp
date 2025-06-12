class Solution {
  public:
      vector<vector<int>> fourSum(vector<int>& nums, int target) {
          int n = nums.size();
          unordered_map<int, vector<pair<int, int>>> twoSum;
          set<vector<int>> result;
          sort(nums.begin(), nums.end());
  
          for (int i = 0; i < n; ++i)
              for (int j = i + 1; j < n; ++j)
                  twoSum[nums[i] + nums[j]].emplace_back(i, j);
  
          for (auto& [sum1, pairs1] : twoSum) {
              int sum2 = target - sum1;
              if (!twoSum.count(sum2)) continue;
  
              for (auto [i, j] : pairs1) {
                  for (auto [k, l] : twoSum[sum2]) {
                      set<int> s = {i, j, k, l};
                      if (s.size() < 4) continue;
  
                      vector<int> quad = {nums[i], nums[j], nums[k], nums[l]};
                      sort(quad.begin(), quad.end());
                      result.insert(quad);
                  }
              }
          }
  
          return vector<vector<int>>(result.begin(), result.end());
      }
  };
  