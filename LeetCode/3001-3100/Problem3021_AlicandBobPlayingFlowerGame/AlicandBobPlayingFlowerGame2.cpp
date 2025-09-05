class Solution {
public:
    long long flowerGame(int n, int m) {
        return ((long long)(n + 1) >> 1) * (m >> 1) + ((long long)n >> 1) * ((m + 1) >> 1);
    }
};
