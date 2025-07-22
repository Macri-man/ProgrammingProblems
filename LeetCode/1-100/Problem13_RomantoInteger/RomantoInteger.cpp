class Solution {
public:
    int romanToInt(const std::string& s) {
        static const int values[128] = { 
            ['I'] = 1, ['V'] = 5, ['X'] = 10, ['L'] = 50, 
            ['C'] = 100, ['D'] = 500, ['M'] = 1000 
        };
        
        int result = 0;
        int n = s.size();
        
        for (int i = 0; i < n; ++i) {
            int value = values[s[i]];
            if (i + 1 < n && values[s[i + 1]] > value) {
                result -= value;
            } else {
                result += value;
            }
        }
        return result;
    }
};
