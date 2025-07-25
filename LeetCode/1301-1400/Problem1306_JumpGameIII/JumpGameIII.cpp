
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int i = q.front();
            q.pop();

            if (arr[i] == 0) {
                return true;
            }

            int next1 = i + arr[i];
            int next2 = i - arr[i];

            if (next1 < n && !visited[next1]) {
                visited[next1] = true;
                q.push(next1);
            }
            if (next2 >= 0 && !visited[next2]) {
                visited[next2] = true;
                q.push(next2);
            }
        }

        return false;
    }
};