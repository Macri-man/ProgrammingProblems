#include <vector>
#include <unordered_set>
#include <utility>
#include <algorithm>
using namespace std;

struct pair_hash {
    size_t operator()(const pair<int, int>& p) const {
        return (hash<int>()(p.first) ^ (hash<int>()(p.second) << 1));
    }
};

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int dir = 0;

        unordered_set<pair<int, int>, pair_hash> obstacleSet;
        for (const auto& obs : obstacles) {
            obstacleSet.insert({obs[0], obs[1]});
        }

        int x = 0, y = 0;
        int maxDistSq = 0;

        for (int cmd : commands) {
            if (cmd == -1) {
                dir = (dir + 1) % 4; 
            } else if (cmd == -2) {
                dir = (dir + 3) % 4; 
            } else {
                for (int i = 0; i < cmd; ++i) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;
                    if (obstacleSet.count({nx, ny})) break;
                    x = nx;
                    y = ny;
                    maxDistSq = max(maxDistSq, x * x + y * y);
                }
            }
        }

        return maxDistSq;
    }
};
