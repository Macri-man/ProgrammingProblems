class Solution {
public:
    string largestGoodInteger(string num) {
        for (char d = '9'; d >= '0'; d--) {
            string target(3, d); 
            if (num.find(target) != string::npos) {
                return target; 
            }
        }
        return "";
    }
};