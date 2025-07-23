class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        const int total = rows * cols;
        vector<vector<int>> result;
        result.reserve(total);

        int dirs[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        auto inBounds = [&](int r, int c) {
            return static_cast<unsigned>(r) < static_cast<unsigned>(rows) &&
                   static_cast<unsigned>(c) < static_cast<unsigned>(cols);
        };

        int r = rStart, c = cStart, step = 1, count = 1;
        result.push_back({r, c});

        while (count < total) {
            for (int i = 0; i < 4; ++i) {
                int dx = dirs[i][0], dy = dirs[i][1];
                for (int j = 0; j < step; ++j) {
                    r += dx;
                    c += dy;
                    if (inBounds(r, c)) {
                        result.push_back({r, c});
                        if (++count == total) return result;
                    }
                }
                if (i % 2 == 1) ++step;
            }
        }

        return result;
    }
};
