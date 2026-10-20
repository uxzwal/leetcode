#include <vector>
#include <algorithm>

class Solution {
public:
    int sortableIntegers(std::vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Create the target sorted version of the array
        std::vector<int> sorted_nums = nums;
        std::sort(sorted_nums.begin(), sorted_nums.end());
        
        int total_sum = 0;
        
        // Step 2: Iterate through all possible divisors k of n
        for (int k = 1; k <= n; ++k) {
            if (n % k != 0) continue;
            
            bool is_sortable = true;
            
            // Step 3: Check each block of size k
            for (int i = 0; i < n; i += k) {
                int drops = 0;
                int drop_idx = -1;
                
                // Count cyclic drops within the current subarray block of nums
                for (int j = 0; j < k; ++j) {
                    if (nums[i + j] > nums[i + (j + 1) % k]) {
                        drops++;
                        drop_idx = j;
                    }
                }
                
                // A cyclically rotated sorted array can have at most 1 drop
                if (drops > 1) {
                    is_sortable = false;
                    break;
                }
                
                // Verify if the elements match sorted_nums when correctly aligned
                // If drops == 0, it's already sorted, start alignment from 0
                int start_offset = (drop_idx + 1) % k; 
                for (int j = 0; j < k; ++j) {
                    if (nums[i + (start_offset + j) % k] != sorted_nums[i + j]) {
                        is_sortable = false;
                        break;
                    }
                }
                
                if (!is_sortable) break;
            }
            
            if (is_sortable) {
                total_sum += k;
            }
        }
        
        return total_sum;
    }
};