
class Solution {
public:
    vector<vector<int>> adj;
    vector<bitset<100>> memo;  

    bitset<100>& dfs(int u) {
        if (memo[u].any())
            return memo[u];

        for (int v : adj[u]) {
            memo[u].set(v);             
            memo[u] |= dfs(v);          
        }
        return memo[u];
    }

    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        adj.resize(numCourses);
        memo.resize(numCourses);

        for (auto& pre : prerequisites) {
            int a = pre[0], b = pre[1];
            adj[a].push_back(b);
        }

        for (int i = 0; i < numCourses; ++i) {
            dfs(i);
        }

        vector<bool> ans;
        for (auto& q : queries) {
            int u = q[0], v = q[1];
            ans.push_back(memo[u].test(v));
        }
        return ans;
    }
};