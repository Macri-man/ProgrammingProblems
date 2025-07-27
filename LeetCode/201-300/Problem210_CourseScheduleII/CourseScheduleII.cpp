class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> inDegree(numCourses);

        for (auto& p : prerequisites) {
            graph[p[1]].emplace_back(p[0]);
            ++inDegree[p[0]];
        }

        vector<int> order;
        order.reserve(numCourses);

        vector<int> queue;
        queue.reserve(numCourses);
        for (int i = 0; i < numCourses; ++i) {
            if (inDegree[i] == 0) queue.push_back(i);
        }

        for (size_t i = 0; i < queue.size(); ++i) {
            int course = queue[i];
            order.push_back(course);
            for (int next : graph[course]) {
                if (--inDegree[next] == 0)
                    queue.push_back(next);
            }
        }

        return (order.size() == numCourses) ? order : vector<int>();
    }
};