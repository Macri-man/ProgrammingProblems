class Solution {
public:
    string intToRoman(int num) {
        static const int values[] = 
            {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        static const string symbols[] = 
            {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        
        string result;
        result.reserve(15);

        for (int i = 0; i < 13; i++) {
            int count = num / values[i];
            num %= values[i];
            for (int j = 0; j < count; j++) {
                result += symbols[i];
            }
        }
        return result;
    }
};
