class Solution {
  public:
      int maxFreeTime(int eventTime, vector<int>& start, vector<int>& end) {
          int n = (int)start.size();
          vector<int> gaps(n + 1);
  
          gaps[0] = start[0];
          for (int i = 1; i < n; ++i)
              gaps[i] = start[i] - end[i - 1];
          gaps[n] = eventTime - end[n - 1];
  
          vector<int> prefixMax(n + 2, 0), suffixMax(n + 2, 0);
          for (int i = 1; i <= n + 1; ++i)
              prefixMax[i] = max(prefixMax[i - 1], gaps[i - 1]);
          for (int i = n; i >= 0; --i)
              suffixMax[i] = max(suffixMax[i + 1], gaps[i]);
  
          int maxFree = *max_element(gaps.begin(), gaps.end());
  
          for (int i = 0; i < n; ++i) {
              int dur = end[i] - start[i];
  
              int left = (i == 0) ? 0 : end[i - 1];
              int right = (i == n - 1) ? eventTime : start[i + 1];
              int mergedGap = right - left;
  
              int largestElsewhereGap = max(prefixMax[i], suffixMax[i + 2]);
  
              int leftoverInMergedGap = 0;
              if (mergedGap >= dur) {
                  leftoverInMergedGap = max(right - (left + dur), (right - dur) - left);
              }
  
              int leftoverElsewhere = (largestElsewhereGap >= dur) ? (largestElsewhereGap - dur) : 0;
  
              int candidate = max(leftoverInMergedGap, leftoverElsewhere);
              maxFree = max(maxFree, candidate);
          }
  
          return maxFree;
      }
  };
  