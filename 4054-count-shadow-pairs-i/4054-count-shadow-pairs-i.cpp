class Solution {
public:
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        // stack: (value, prefix_sum_of_counts)
        vector<pair<long long,long long>> st;
        long long total = 0; // sum of counts of all elements currently in stack

        for (int j = 0; j < n; ++j) {
            long long v = nums[j];
            long long merged = 0;
            while (!st.empty() && st.back().first >= v) {
                if (st.back().first == v) merged += st.back().second - (st.size() >= 2 ? st[st.size()-2].second : 0);
                total -= st.back().second - (st.size() >= 2 ? st[st.size()-2].second : 0);
                st.pop_back();
            }
            ans += total;
            long long cnt = 1 + merged;
            st.push_back({v, (st.empty() ? 0 : st.back().second) + cnt});
            total += cnt;
        }
        return ans;
    }
};