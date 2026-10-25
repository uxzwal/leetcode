#include <vector>
#include <set>
#include <cmath>

using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        set<long long> window; // Use long long to prevent integer overflow during math operations

        for (int i = 0; i < nums.size(); i++) {
            // 1. Maintain the sliding window size of at most 'indexDiff'
            if (i > indexDiff) {
                window.erase(nums[i - indexDiff - 1]);
            }

            // 2. Look for the smallest element in the window that is >= nums[i] - valueDiff
            auto it = window.lower_bound((long long)nums[i] - valueDiff);

            // 3. Check if this element also satisfies the upper bound constraint (<= nums[i] + valueDiff)
            if (it != window.end() && *it <= (long long)nums[i] + valueDiff) {
                return true;
            }

            // 4. Insert the current element into the window
            window.insert(nums[i]);
        }

        return false;
    }
};
