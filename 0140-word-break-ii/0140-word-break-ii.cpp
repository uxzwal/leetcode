class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        unordered_map<int, vector<string>> memo;
        function<vector<string>(int)> dfs = [&](int i) -> vector<string> {
            if (memo.count(i)) return memo[i];
            vector<string> res;
            if (i == s.size()) { res.push_back(""); return memo[i] = res; }
            for (int j = i + 1; j <= s.size(); j++) {
                string word = s.substr(i, j - i);
                if (dict.count(word)) {
                    for (string& rest : dfs(j)) {
                        res.push_back(rest.empty() ? word : word + " " + rest);
                    }
                }
            }
            return memo[i] = res;
        };
        return dfs(0);
    }
};