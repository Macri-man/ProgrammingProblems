class Solution {
public:
    long long minimumDifference(vector<int>& nums) {
        int n = nums.size() / 3;

        vector<long long> leftSums(2 * n + 1);
        priority_queue<int> maxHeap; 
        long long leftSum = 0;

        for (int i = 0; i < 2 * n; ++i) {
            maxHeap.push(nums[i]);
            leftSum += nums[i];

            if ((int)maxHeap.size() > n) {
                leftSum -= maxHeap.top();
                maxHeap.pop();
            }

            if ((int)maxHeap.size() == n) {
                leftSums[i] = leftSum;
            }
        }

        vector<long long> rightSums(2 * n + 1);
        priority_queue<int, vector<int>, greater<int>> minHeap; 
        long long rightSum = 0;

        for (int i = nums.size() - 1; i >= n; --i) {
            minHeap.push(nums[i]);
            rightSum += nums[i];

            if ((int)minHeap.size() > n) {
                rightSum -= minHeap.top();
                minHeap.pop();
            }

            if ((int)minHeap.size() == n) {
                rightSums[i - n] = rightSum;
            }
        }

        long long res = LLONG_MAX;
        for (int i = n - 1; i < 2 * n; ++i) {
            res = min(res, leftSums[i] - rightSums[i - n + 1]);
        }

        return res;
    }
};
