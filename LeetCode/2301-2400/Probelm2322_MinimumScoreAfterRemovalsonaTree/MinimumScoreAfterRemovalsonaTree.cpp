class Solution {
public:
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<vector<int>> tree(n);
        vector<int> xorSubtree(n), inTime(n), outTime(n);
        vector<pair<int, int>> edgeList;
        int timer = 0;

        for (auto& e : edges) {
            tree[e[0]].push_back(e[1]);
            tree[e[1]].push_back(e[0]);
        }

        function<void(int, int)> dfs = [&](int node, int parent) {
            xorSubtree[node] = nums[node];
            inTime[node] = ++timer;
            for (int nei : tree[node]) {
                if (nei == parent) continue;
                edgeList.emplace_back(node, nei);
                dfs(nei, node);
                xorSubtree[node] ^= xorSubtree[nei];
            }
            outTime[node] = ++timer;
        };

        dfs(0, -1);
        int totalXor = xorSubtree[0];
        int ans = INT_MAX;

        for (int i = 0; i < edgeList.size(); ++i) {
            int v1 = edgeList[i].second;
            for (int j = i + 1; j < edgeList.size(); ++j) {
                int v2 = edgeList[j].second;

                int x = 0, y = 0, z = 0;
                if (inTime[v1] < inTime[v2] && outTime[v2] < outTime[v1]) {
                    x = xorSubtree[v2];
                    y = xorSubtree[v1] ^ xorSubtree[v2];
                    z = totalXor ^ xorSubtree[v1];
                } else if (inTime[v2] < inTime[v1] && outTime[v1] < outTime[v2]) {
                    x = xorSubtree[v1];
                    y = xorSubtree[v2] ^ xorSubtree[v1];
                    z = totalXor ^ xorSubtree[v2];
                } else {
                    x = xorSubtree[v1];
                    y = xorSubtree[v2];
                    z = totalXor ^ xorSubtree[v1] ^ xorSubtree[v2];
                }

                int mx = max(x, max(y, z));
                int mn = min(x, min(y, z));
                ans = min(ans, mx - mn);
            }
        }

        return ans;
    }
};
