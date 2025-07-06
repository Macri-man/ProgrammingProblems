#include <vector>
#include <unordered_map>
using namespace std;

class FindSumPairs {
private:
    const vector<int>& nums1;
    vector<int> nums2;
    unordered_map<int, int> freq2;
    unordered_map<int, int> freq1;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : nums1(nums1), nums2(nums2) {
        for (int num : nums2) {
            ++freq2[num];
        }
        for (int num : nums1) {
            ++freq1[num];
        }
    }

    void add(int index, int val) {
        int old_val = nums2[index];
        int new_val = old_val + val;
        nums2[index] = new_val;

        if (--freq2[old_val] == 0) {
            freq2.erase(old_val);
        }
        ++freq2[new_val];
    }

    int count(int tot) {
        int result = 0;
        for (const auto& [a, cnt1] : freq1) {
            int b = tot - a;
            auto it = freq2.find(b);
            if (it != freq2.end()) {
                result += cnt1 * it->second;
            }
        }
        return result;
    }
};


/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */