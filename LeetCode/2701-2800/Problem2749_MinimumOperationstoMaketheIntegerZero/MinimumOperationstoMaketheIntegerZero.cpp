class Solution {
public:
    int popcountULL(unsigned long long x) {
        int cnt = 0;
        while (x) {
            x &= (x - 1);
            ++cnt;
        }
        return cnt;
    }

    int makeTheIntegerZero(int num1, int num2) {
        for (int k = 1; k <= 60; ++k) {
            long long x = (long long)num1 - (long long)k * num2;
            if (x < 0) continue;
            int bits = popcountULL((unsigned long long)x);
            if (bits <= k && (long long)k <= x) {
                return k;
            }
        }
        return -1;
    }
};