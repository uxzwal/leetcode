class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        // Step 1: Find the global minimum and maximum
        int min_val = nums[0];
        int max_val = nums[0];
        for (int num : nums) {
            min_val = min(min_val, num);
            max_val = max(max_val, num);
        }

        // If all elements are identical, the gap is 0
        if (max_val == min_val) return 0;

        // Step 2: Calculate bucket size and count
        int bucket_size = max(1, (max_val - min_val) / (n - 1));
        int bucket_count = (max_val - min_val) / bucket_size + 1;

        // Step 3: Initialize tracking arrays for each bucket
        vector<int> bucket_min(bucket_count, INT_MAX);
        vector<int> bucket_max(bucket_count, INT_MIN);
        vector<bool> has_element(bucket_count, false);

        // Step 4: Populate the buckets
        for (int num : nums) {
            int idx = (num - min_val) / bucket_size;
            bucket_min[idx] = min(bucket_min[idx], num);
            bucket_max[idx] = max(bucket_max[idx], num);
            has_element[idx] = true;
        }

        // Step 5: Find the maximum gap between adjacent non-empty buckets
        int max_gap = 0;
        int prev_max = min_val;

        for (int i = 0; i < bucket_count; ++i) {
            if (!has_element[i]) continue; // Skip empty buckets

            // Gap is between current bucket's min and previous bucket's max
            max_gap = max(max_gap, bucket_min[i] - prev_max);
            prev_max = bucket_max[i];
        }

        return max_gap;
    }
};