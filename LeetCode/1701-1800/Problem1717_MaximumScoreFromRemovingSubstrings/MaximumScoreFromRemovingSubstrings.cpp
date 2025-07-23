class Solution {
public:
    int removeSubstr(vector<char>& s, char a, char b, int val) {
        int score = 0;
        int writeIndex = 0;
        for (int readIndex = 0; readIndex < (int)s.size(); ++readIndex) {
            char c = s[readIndex];
            if (writeIndex > 0 && s[writeIndex - 1] == a && c == b) {
                --writeIndex;
                score += val;
            } else {
                s[writeIndex++] = c;
            }
        }
        s.resize(writeIndex);
        return score;
    }

    int maximumGain(string s, int x, int y) {
        vector<char> s_vec(s.begin(), s.end());
        s_vec.reserve(s.size()); 

        int total = 0;
        if (x >= y) {
            total += removeSubstr(s_vec, 'a', 'b', x);
            total += removeSubstr(s_vec, 'b', 'a', y);
        } else {
            total += removeSubstr(s_vec, 'b', 'a', y);
            total += removeSubstr(s_vec, 'a', 'b', x);
        }
        return total;
    }
};
