class Solution {
public:
bool canReach(string s, int minJump, int maxJump) {
    int n = s.size();
    if (s[n - 1] != '0') return false;

    int reachable = 0;
    deque<int> dq;
    dq.push_back(0);

    for (int i = 1; i < n; ++i) {
        while (!dq.empty() && dq.front() < i - maxJump) dq.pop_front();

        if (i >= minJump && s[i] == '0' && !dq.empty() && dq.front() <= i - minJump) {
            dq.push_back(i);
        }
    }

    return !dq.empty() && dq.back() == n - 1;
}
};