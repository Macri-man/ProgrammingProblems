class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle;
        triangle.reserve(numRows);

        for (int i = 0; i < numRows; ++i) {
            vector<int> row(i + 1, 1);
            int half = i / 2;

            for (int j = 1; j <= half; ++j) {
                int val = triangle[i - 1][j - 1] + triangle[i - 1][j];
                row[j] = val;
                row[i - j] = val;
            }

            triangle.push_back(std::move(row));
        }

        return triangle;
    }
};
