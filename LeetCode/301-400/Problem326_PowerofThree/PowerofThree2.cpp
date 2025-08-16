class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0) return false;
        double val = std::log10(n) / std::log10(3);
        return std::abs(val - round(val)) < 1e-10;
    }
};