class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
        int left = 0, right = n - 1, top = 0, bottom = n - 1, num = 1;
        while (left <= right && top <= bottom) {
            for (int col = left; col <= right; ++col) matrix[top][col] = num++;
            top++;
            for (int row = top; row <= bottom; ++row) matrix[row][right] = num++;
            right--;
            if (top <= bottom) {
                for (int col = right; col >= left; --col) matrix[bottom][col] = num++;
                bottom--;
            }
            if (left <= right) {
                for (int row = bottom; row >= top; --row) matrix[row][left] = num++;
                left++;
            }
        }
        return matrix;
    }
};
