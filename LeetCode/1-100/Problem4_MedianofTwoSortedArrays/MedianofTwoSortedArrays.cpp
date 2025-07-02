#include <vector>
#include <algorithm>
#include <limits>
#include <stdexcept>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(const vector<int>& nums1, const vector<int>& nums2) {
        const vector<int>& A = (nums1.size() <= nums2.size()) ? nums1 : nums2;
        const vector<int>& B = (nums1.size() <= nums2.size()) ? nums2 : nums1;

        int m = A.size();
        int n = B.size();
        int low = 0, high = m;

        while (low <= high) {
            int cutA = (low + high) / 2;
            int cutB = (m + n + 1) / 2 - cutA;

            int leftA  = (cutA == 0) ? numeric_limits<int>::min() : A[cutA - 1];
            int rightA = (cutA == m) ? numeric_limits<int>::max() : A[cutA];
            int leftB  = (cutB == 0) ? numeric_limits<int>::min() : B[cutB - 1];
            int rightB = (cutB == n) ? numeric_limits<int>::max() : B[cutB];

            if (leftA <= rightB && leftB <= rightA) {
                if ((m + n) % 2 == 0) {
                    return (max(leftA, leftB) + min(rightA, rightB)) / 2.0;
                } else {
                    return static_cast<double>(max(leftA, leftB));
                }
            } else if (leftA > rightB) {
                high = cutA - 1;
            } else {
                low = cutA + 1;
            }
        }

    }
};
