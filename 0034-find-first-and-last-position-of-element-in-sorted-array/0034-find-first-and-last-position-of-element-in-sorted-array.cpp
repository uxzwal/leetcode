class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int right = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        if (left <= right && left < nums.size() && nums[left] == target)
            return {left, right};
        return {-1, -1};
    }
};