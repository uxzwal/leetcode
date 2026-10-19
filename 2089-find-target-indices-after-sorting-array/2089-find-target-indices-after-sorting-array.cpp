class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int smaller_count = 0;
        int equal_count = 0;
        
        // Count elements smaller than and equal to the target
        for (int num : nums) {
            if (num < target) {
                smaller_count++;
            } else if (num == target) {
                equal_count++;
            }
        }
        
        // Generate the sorted target indices
        vector<int> result;
        for (int i = 0; i < equal_count; i++) {
            result.push_back(smaller_count + i);
        }
        
        return result;
    }
};
