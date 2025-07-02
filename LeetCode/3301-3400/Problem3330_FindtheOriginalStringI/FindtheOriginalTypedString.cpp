class Solution {
  public:
      int possibleStringCount(string word) {
          int count = 1;  // Always include the original string
          int n = word.size();
          int i = 0;
  
          while (i < n) {
              int j = i + 1;
              while (j < n && word[j] == word[i]) {
                  ++j;
              }
              int group_len = j - i;
              if (group_len > 1) {
                  count += group_len - 1;
              }
              i = j;
          }
  
          return count;
      }
  };
  