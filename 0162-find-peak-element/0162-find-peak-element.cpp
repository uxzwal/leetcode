class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        
        // Binary search to find the peak index
        while (left < right) {
            int mid = left + (right - left) / 2;
            
            if (nums[mid] > nums[mid + 1]) {
                // We are on a downward slope; peak is to the left (including mid)
                right = mid;
            } else {
                // We are on an upward slope; peak is strictly to the right
                left = mid + 1;
            }
        }
        
        // At the end, left == right pointing to a peak element
        return left;
    }
};
