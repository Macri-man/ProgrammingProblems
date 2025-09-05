class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        const int MAX = 51;          
        int psum[MAX+1][MAX+1] = {};  

        for (auto &p : points) {
            int x = p[0] + 1;
            int y = p[1] + 1;
            psum[x][y] = 1;
        }

        for (int x = 1; x <= MAX; ++x) {
            int rowSum = 0;
            for (int y = 1; y <= MAX; ++y) {
                rowSum += psum[x][y];              
                psum[x][y] = psum[x-1][y] + rowSum;
            }
        }

        int n = points.size();
        vector<pair<int,int>> pts(n);
        for (int i = 0; i < n; ++i)
            pts[i] = {points[i][0] + 1, points[i][1] + 1};

        auto rectCount = [&](int x1, int y1, int x2, int y2) {
            return psum[x2][y2] - psum[x1-1][y2] - psum[x2][y1-1] + psum[x1-1][y1-1];
        };

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int x1 = pts[i].first, y1 = pts[i].second;
            for (int j = 0; j < n; ++j) {
                if (i == j) continue;
                int x2 = pts[j].first, y2 = pts[j].second;

                if (x1 <= x2 && y1 >= y2 && (x1 < x2 || y1 > y2)) {
                    int xmin = (x1 < x2 ? x1 : x2);
                    int xmax = (x1 > x2 ? x1 : x2);
                    int ymin = (y1 < y2 ? y1 : y2);
                    int ymax = (y1 > y2 ? y1 : y2);

                    if (rectCount(xmin, ymin, xmax, ymax) == 2) {
                        ++ans;
                    }
                }
            }
        }
        return ans;
    }
};