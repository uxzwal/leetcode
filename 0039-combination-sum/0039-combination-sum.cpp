class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> cur;
        backtrack(candidates, target, 0, cur, res);
        return res;
    }
    
    void backtrack(vector<int>& candidates, int target, int start, vector<int>& cur, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(cur);
            return;
        }
        if (target < 0) return;
        for (int i = start; i < candidates.size(); i++) {
            cur.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, cur, res);
            cur.pop_back();
        }
    }
};