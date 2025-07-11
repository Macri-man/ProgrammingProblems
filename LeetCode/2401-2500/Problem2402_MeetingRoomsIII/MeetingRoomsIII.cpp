#include <vector>
#include <queue>
#include <algorithm>
#include <array>
using namespace std;

class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());

        array<int, 100> count = {}; 

        priority_queue<int, vector<int>, greater<>> available;
        for (int i = 0; i < n; ++i) available.push(i);

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> busy;

        for (const auto& m : meetings) {
            long long start = m[0], end = m[1];

            while (!busy.empty() && busy.top().first <= start) {
                available.push(busy.top().second);
                busy.pop();
            }

            if (!available.empty()) {
                int room = available.top(); available.pop();
                count[room]++;
                busy.emplace(end, room);
            } else {
                auto [endTime, room] = busy.top(); busy.pop();
                count[room]++;
                busy.emplace(endTime + (end - start), room);
            }
        }

        int maxRoom = 0;
        for (int i = 1; i < n; ++i) {
            if (count[i] > count[maxRoom]) maxRoom = i;
        }
        return maxRoom;
    }
};
