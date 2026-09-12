class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans;
        string cur;
        function<void(int)> dfs = [&](int i) {
            if (i == digits.size()) {
                ans.push_back(cur);
                return;
            }
            for (char c : mp[digits[i] - '0']) {
                cur.push_back(c);
                dfs(i + 1);
                cur.pop_back();
            }
        };
        dfs(0);
        return ans;
    }
};