#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        long long ans = 0;
        int prefix_cnt = 0;
        
        // Map to store frequency of (prefix_cnt % modulo)
        unordered_map<int, int> count_map;
        
        // Base case: A prefix sum of 0 has occurred 1 time initially
        count_map[0] = 1;
        
        for (int num : nums) {
            // Check if the current element satisfies the condition
            if (num % modulo == k) {
                prefix_cnt = (prefix_cnt + 1) % modulo;
            }
            
            // Find the required prefix remainder that satisfies: 
            // (prefix_cnt - target + modulo) % modulo == k
            int target = (prefix_cnt - k + modulo) % modulo;
            
            // If the target remainder exists in our map, add its frequency to the answer
            if (count_map.count(target)) {
                ans += count_map[target];
            }
            
            // Record the current prefix remainder in the map
            count_map[prefix_cnt]++;
        }
        
        return ans;
    }
};
