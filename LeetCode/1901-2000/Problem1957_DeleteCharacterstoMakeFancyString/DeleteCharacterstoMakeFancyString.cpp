class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1;
        int size = s.size();

        for (int i = 0; i < size; ++i) {
            if (i > 0 && s[i] == s[i - 1]) {
                count++;
            } else {
                count = 1;
            }

            if (count <= 2) {
                result += s[i];
            }
        }

        return result;
    }
};