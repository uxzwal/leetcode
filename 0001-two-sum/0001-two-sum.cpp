#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Map to store: key = number value, value = index
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];
            
            // If the complement is found, return its index and current index
            if (numMap.count(complement)) {
                return {numMap[complement], i};
            }
            
            // Otherwise, add the current number and index to the map
            numMap[nums[i]] = i;
        }
        
        // Return empty vector if no solution is found (though constraint guarantees one exists)
        return {};
    }
};
