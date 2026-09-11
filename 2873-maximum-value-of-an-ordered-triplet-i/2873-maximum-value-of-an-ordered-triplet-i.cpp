class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long maxValue = 0;
        
        for (int j = 1; j < n - 1; j++) {
            int maxLeft = 0;
            for (int i = 0; i < j; i++) {
                maxLeft = max(maxLeft, nums[i]);
            }
            
            for (int k = j + 1; k < n; k++) {
                long long value = (long long)(maxLeft - nums[j]) * nums[k];
                maxValue = max(maxValue, value);
            }
        }
        
        return maxValue;
    }
};