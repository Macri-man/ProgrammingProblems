
class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSq = 0;  
        int maxArea = 0;

        for (auto &rect : dimensions) {
            int length = rect[0];
            int width = rect[1];
            int diagSq = length * length + width * width;
            int area = length * width;

            if (diagSq > maxDiagonalSq) {
                maxDiagonalSq = diagSq;
                maxArea = area;
            } else if (diagSq == maxDiagonalSq) {
                maxArea = max(maxArea, area);
            }
        }

        return maxArea;
    }
};
