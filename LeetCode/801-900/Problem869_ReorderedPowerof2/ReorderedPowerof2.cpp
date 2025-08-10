class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s = to_string(n);
        sort(s.begin(), s.end());
        
        for (int i = 0; i < 31; ++i) {
            string p = to_string(1 << i);
            sort(p.begin(), p.end());
            if (s == p) return true;
        }
        return false;
    }
};