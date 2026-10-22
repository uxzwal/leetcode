#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;
        
        // Find the index of element 0
        int pos0 = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                pos0 = i;
                break;
            }
        }
        
        bool is_ascending = true;
        bool is_descending = true;
        
        // Verify if the array is a valid cyclic shift of ascending or descending order
        for (int i = 0; i < n; ++i) {
            if (nums[i] != (i - pos0 + n) % n) {
                is_ascending = false;
            }
            if (nums[i] != (pos0 - i + n) % n) {
                is_descending = false;
            }
        }
        
        int ans = INT_MAX;
        
        // Calculate the minimal operations for the valid configurations
        if (is_ascending) {
            ans = min(ans, pos0);
            ans = min(ans, n - pos0 + 2);
        }
        if (is_descending) {
            ans = min(ans, ((pos0 + 1) % n) + 1);
            ans = min(ans, n - pos0);
        }
        
        return ans == INT_MAX ? -1 : ans;
    }
};