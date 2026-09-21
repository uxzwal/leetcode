class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long> result(k, 0);
        vector<long long> prev(k, 0);
        
        for (int i = 0; i < n; i++) {
            vector<long long> curr(k, 0);
            int val = nums[i] % k;
            
            // Subarray starting at i
            curr[val]++;
            
            // Extend subarrays ending at i-1
            for (int r = 0; r < k; r++) {
                if (prev[r] > 0) {
                    int newR = (r * val) % k;
                    curr[newR] += prev[r];
                }
            }
            
            for (int r = 0; r < k; r++) {
                result[r] += curr[r];
            }
            
            prev = curr;
        }
        
        return result;
    }
};