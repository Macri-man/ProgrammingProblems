class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> result;
        if (s.empty() || words.empty()) return result;

        int wordLen = words[0].size();
        int wordCount = words.size();
        int totalLen = wordLen * wordCount;
        int sLen = s.size();

        unordered_map<string, int> wordFreq;
        for (const string& word : words)
            wordFreq[word]++;

        for (int i = 0; i < wordLen; ++i) {
            int left = i, right = i;
            unordered_map<string, int> currFreq;

            while (right + wordLen <= sLen) {
                string word = s.substr(right, wordLen);
                right += wordLen;

                if (wordFreq.count(word)) {
                    currFreq[word]++;

                    while (currFreq[word] > wordFreq[word]) {
                        string leftWord = s.substr(left, wordLen);
                        currFreq[leftWord]--;
                        left += wordLen;
                    }

                    if (right - left == totalLen)
                        result.push_back(left);
                } else {
                    currFreq.clear();
                    left = right;
                }
            }
        }

        return result;
    }
};
