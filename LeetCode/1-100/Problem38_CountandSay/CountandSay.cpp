class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string prev = countAndSay(n - 1);
        string res;
        int cnt = 1;
        for (int i = 1; i <= prev.size(); ++i) {
            if (i < prev.size() && prev[i] == prev[i - 1]) {
                ++cnt;                    
            } else {
                res += to_string(cnt) + prev[i - 1];
                cnt = 1;                    
            }
        }
        return res;
    }
};