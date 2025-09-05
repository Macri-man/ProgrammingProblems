
class Solution {
public:
    struct Compare {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) {
            long long p1 = a.first, t1 = a.second;
            long long p2 = b.first, t2 = b.second;
            return (t1 - p1) * (t2 * (t2 + 1)) < (t2 - p2) * (t1 * (t1 + 1));
        }
    };
    
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, Compare> pq;
        
        for (auto &c : classes)
            pq.emplace(c[0], c[1]);
        
        while (extraStudents--) {
            auto [p, t] = pq.top(); pq.pop();
            p++; t++;
            pq.emplace(p, t);
        }
        
        double total = 0.0;
        while (!pq.empty()) {
            auto [p, t] = pq.top(); pq.pop();
            total += (double)p / t;
        }
        return total / classes.size();
    }
};
