class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> heights(n, 0);
        vector<int> sum(n, 0);
        vector<int> st; st.reserve(n);
        int res = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 0) heights[j] = 0;
                else heights[j] += 1;
            }

            st.clear();

            for (int j = 0; j < n; j++) {
                while (!st.empty() && heights[st.back()] > heights[j]) {
                    st.pop_back();
                }

                if (!st.empty()) {
                    int prev = st.back();
                    sum[j] = sum[prev] + heights[j] * (j - prev);
                } else {
                    sum[j] = heights[j] * (j + 1);
                }

                st.push_back(j);
                res += sum[j];
            }
        }
        return res;
    }
};
