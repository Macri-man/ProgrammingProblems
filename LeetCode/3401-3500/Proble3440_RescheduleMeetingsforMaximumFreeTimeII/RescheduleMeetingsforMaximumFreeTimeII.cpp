class Solution {
    public:
        int maxFreeTime(int eventTime, vector<int>& start, vector<int>& end) {
            int n = (int)start.size();
            vector<long long> gaps(n + 1);
    
            gaps[0] = start[0];
            for (int i = 1; i < n; ++i)
                gaps[i] = start[i] - end[i - 1];
            gaps[n] = (long long)eventTime - end[n - 1];
    
            vector<long long> prefixMax(n + 2, 0), suffixMax(n + 2, 0);
            for (int i = 1; i <= n + 1; ++i)
                prefixMax[i] = max(prefixMax[i - 1], gaps[i - 1]);
            for (int i = n; i >= 0; --i)
                suffixMax[i] = max(suffixMax[i + 1], gaps[i]);
    
            long long maxFree = *max_element(gaps.begin(), gaps.end());
    
            for (int i = 0; i < n; ++i) {
                long long dur = end[i] - start[i];
    
                long long mergedGap = gaps[i] + dur + gaps[i + 1];
    
                long long largestElsewhereGap = max(prefixMax[i], suffixMax[i + 2]);
    
                long long leftoverElsewhere = (largestElsewhereGap >= dur) ? (largestElsewhereGap - dur) : -1;
    
                long long candidate;
                if (leftoverElsewhere >= 0) {
                    candidate = max(mergedGap, leftoverElsewhere);
                } else {
                    candidate = mergedGap - dur;
                }
    
                maxFree = max(maxFree, candidate);
            }
    
            return (int)maxFree;
        }
    };
    