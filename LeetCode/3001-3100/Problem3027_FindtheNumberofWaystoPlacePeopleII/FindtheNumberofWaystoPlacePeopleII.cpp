class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        
        bool vertical = true, horizontal = true;
        int x0 = points[0][0], y0 = points[0][1];
        for (auto& p : points) {
            if (p[0] != x0) vertical = false;
            if (p[1] != y0) horizontal = false;
        }
        if (vertical || horizontal) {
            if (vertical) sort(points.begin(), points.end(), [](auto& a, auto& b) { return a[1] > b[1]; });
            else sort(points.begin(), points.end(), [](auto& a, auto& b) { return a[0] < b[0]; });
            return n - 1;
        }

        sort(points.begin(), points.end(), [](auto& a, auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
        });

        int ans = 0;
        for (int i = 0; i < n; i++) {
            int xA = points[i][0], yA = points[i][1];
            int maxYB = INT_MIN;
            for (int j = i + 1; j < n; j++) {
                int xB = points[j][0], yB = points[j][1];
                if (yB > yA) continue;
                bool valid = true;
                if (yB < maxYB) continue;
                for (int k = i + 1; k < j; k++) {
                    int x = points[k][0], y = points[k][1];
                    if (xA <= x && x <= xB && yB <= y && y <= yA) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    ans++;
                    maxYB = max(maxYB, yB); 
                }
            }
        }
        return ans;
    }
};