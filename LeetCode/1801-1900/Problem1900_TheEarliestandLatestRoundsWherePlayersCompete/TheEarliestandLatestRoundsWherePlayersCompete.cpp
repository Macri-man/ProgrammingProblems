#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n, fp, sp;
    unordered_map<int, pair<int,int>> memo;

    pair<int,int> dfs(int mask) {
        if (memo.count(mask)) return memo[mask];

        array<int, 28> players{};
        int cnt = 0;
        for (int i = 0; i < n; ++i)
            if (mask & (1 << i))
                players[cnt++] = i+1;

        int pos_fp = -1, pos_sp = -1;
        for (int i = 0; i < cnt; ++i) {
            if (players[i] == fp) pos_fp = i;
            if (players[i] == sp) pos_sp = i;
        }

        if (pos_fp + pos_sp == cnt - 1) return {1,1}; 

        int minR = INT_MAX, maxR = INT_MIN;
        int half = cnt / 2;

        function<void(int,int)> backtrack = [&](int idx, int curMask) {
            if (idx == half) {
                if (cnt % 2 == 1) {
                    curMask |= (1 << (players[half]-1));
                }
                auto [ear, lat] = dfs(curMask);
                if (ear != INT_MAX) minR = min(minR, ear + 1);
                if (lat != INT_MIN) maxR = max(maxR, lat + 1);
                return;
            }

            int left = players[idx];
            int right = players[cnt - 1 - idx];

            if (left == fp || left == sp) {
                backtrack(idx + 1, curMask | (1 << (left - 1)));
            } else if (right == fp || right == sp) {
                backtrack(idx + 1, curMask | (1 << (right - 1)));
            } else {
                backtrack(idx + 1, curMask | (1 << (left - 1)));
                backtrack(idx + 1, curMask | (1 << (right - 1)));
            }
        };

        backtrack(0, 0);
        return memo[mask] = {minR, maxR};
    }

    vector<int> earliestAndLatest(int _n, int _fp, int _sp) {
        n = _n; fp = _fp; sp = _sp;
        int fullMask = (1 << n) - 1;
        auto [ear, lat] = dfs(fullMask);
        return {ear, lat};
    }
};
