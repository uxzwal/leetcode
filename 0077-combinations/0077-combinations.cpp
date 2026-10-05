class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> cur;
        function<void(int)> backtrack = [&](int start) {
            if (cur.size() == k) { ans.push_back(cur); return; }
            for (int i = start; i <= n - (k - cur.size()) + 1; ++i) {
                cur.push_back(i);
                backtrack(i + 1);
                cur.pop_back();
            }
        };
        backtrack(1);
        return ans;
    }
};