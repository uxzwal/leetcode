class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int)> dfs = [&](int i) {
            if (i == nums.size()) { ans.push_back(cur); return; }
            dfs(i + 1); // not take
            cur.push_back(nums[i]);
            dfs(i + 1); // take
            cur.pop_back();
        };
        dfs(0);
        return ans;
    }
};