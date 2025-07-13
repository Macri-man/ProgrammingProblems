class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        int n = players.size(), m = trainers.size();

        std::sort(players.begin(), players.end());
        std::sort(trainers.begin(), trainers.end());

        int i = 0, j = 0, match = 0;

        while (i < n && j < m) {
            if (players[i] <= trainers[j]) {
                ++match;
                ++i;
                ++j;
            } else {
                ++j;
            }
        }
        return match;
    }
};
