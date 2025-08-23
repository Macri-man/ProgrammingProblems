
class Solution {
public:
    int n, m;
    vector<vector<int>> grid;

    int area(int r1,int r2,int c1,int c2) {
        int rr1 = n, rr2 = -1, cc1 = m, cc2 = -1;
        bool found = false;
        for (int r = r1; r <= r2; r++) {
            for (int c = c1; c <= c2; c++) {
                if (grid[r][c] == 1) {
                    found = true;
                    rr1 = min(rr1, r); rr2 = max(rr2, r);
                    cc1 = min(cc1, c); cc2 = max(cc2, c);
                }
            }
        }
        if (!found) return INT_MAX;
        return (rr2-rr1+1) * (cc2-cc1+1);
    }

    int minimumSum(vector<vector<int>>& g) {
        grid = g;
        n = grid.size(), m = grid[0].size();
        int ans = INT_MAX;

        for (int c1 = 0; c1 < m; c1++) {
            for (int c2 = c1+1; c2 < m; c2++) {
                int a1 = area(0, n-1, 0, c1);
                int a2 = area(0, n-1, c1+1, c2);
                int a3 = area(0, n-1, c2+1, m-1);
                if (a1!=INT_MAX && a2!=INT_MAX && a3!=INT_MAX)
                    ans = min(ans, a1+a2+a3);
            }
        }

        for (int r1 = 0; r1 < n; r1++) {
            for (int r2 = r1+1; r2 < n; r2++) {
                int a1 = area(0, r1, 0, m-1);
                int a2 = area(r1+1, r2, 0, m-1);
                int a3 = area(r2+1, n-1, 0, m-1);
                if (a1!=INT_MAX && a2!=INT_MAX && a3!=INT_MAX)
                    ans = min(ans, a1+a2+a3);
            }
        }

        for (int c = 0; c < m-1; c++) {
            for (int r = 0; r < n-1; r++) {
                int a1 = area(0, n-1, 0, c);
                int a2 = area(0, r, c+1, m-1);
                int a3 = area(r+1, n-1, c+1, m-1);
                if (a1!=INT_MAX && a2!=INT_MAX && a3!=INT_MAX)
                    ans = min(ans, a1+a2+a3);

                a1 = area(0, n-1, c+1, m-1);
                a2 = area(0, r, 0, c);
                a3 = area(r+1, n-1, 0, c);
                if (a1!=INT_MAX && a2!=INT_MAX && a3!=INT_MAX)
                    ans = min(ans, a1+a2+a3);
            }
        }s

        for (int r = 0; r < n-1; r++) {
            for (int c = 0; c < m-1; c++) {
                int a1 = area(0, r, 0, m-1);
                int a2 = area(r+1, n-1, 0, c);
                int a3 = area(r+1, n-1, c+1, m-1);
                if (a1!=INT_MAX && a2!=INT_MAX && a3!=INT_MAX)
                    ans = min(ans, a1+a2+a3);

                a1 = area(r+1, n-1, 0, m-1);
                a2 = area(0, r, 0, c);
                a3 = area(0, r, c+1, m-1);
                if (a1!=INT_MAX && a2!=INT_MAX && a3!=INT_MAX)
                    ans = min(ans, a1+a2+a3);
            }
        }

        return ans;
    }
};