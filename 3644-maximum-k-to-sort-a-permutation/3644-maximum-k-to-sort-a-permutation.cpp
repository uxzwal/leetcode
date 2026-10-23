#include <vector>

class Solution {
public:
    int sortPermutation(std::vector<int>& nums) {
        int max_k = -1; // Initialize with -1 (all bits set to 1 in 2's complement)
        
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] != i) {
                if (max_k == -1) {
                    max_k = nums[i];
                } else {
                    max_k &= nums[i];
                }
            }
        }
        
        // If the array is already sorted, max_k remains -1; return 0.
        return (max_k == -1) ? 0 : max_k;
    }
};