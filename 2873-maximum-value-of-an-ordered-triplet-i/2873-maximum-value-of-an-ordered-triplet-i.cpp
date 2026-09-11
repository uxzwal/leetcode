class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;
        
        // Precompute maximum value to the right of each index
        vector<int> maxRight(n);
        maxRight[n-1] = nums[n-1];
        for (int i = n-2; i >= 0; i--) {
            maxRight[i] = max(maxRight[i+1], nums[i]);
        }
        
        // Precompute maximum value to the left of each index
        int maxLeft = nums[0];
        long long result = 0;
        
        for (int j = 1; j < n-1; j++) {
            // maxLeft is max(nums[0..j-1])
            // maxRight[j+1] is max(nums[j+1..n-1])
            long long value = (long long)(maxLeft - nums[j]) * maxRight[j+1];
            result = max(result, value);
            
            // Update maxLeft for next iteration
            maxLeft = max(maxLeft, nums[j]);
        }
        
        return result;
    }
};