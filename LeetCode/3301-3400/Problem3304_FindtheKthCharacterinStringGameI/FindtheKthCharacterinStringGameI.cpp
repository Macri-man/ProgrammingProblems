class Solution {
  public:
      char kthCharacter(int k) {
          std::string word = "a";
          
          while (word.length() < k) {
              std::string nextPart;
              for (char c : word) {
                  char nextChar = (c - 'a' + 1) % 26 + 'a';
                  nextPart += nextChar;
              }
              word += nextPart;
          }
  
          return word[k - 1];
      }
  };
  