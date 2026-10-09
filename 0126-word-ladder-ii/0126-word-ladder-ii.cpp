class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        if (!dict.count(endWord)) return res;
        unordered_map<string, vector<string>> parents;
        unordered_set<string> current{beginWord}, visited{beginWord};
        bool found = false;
        while (!current.empty() && !found) {
            unordered_set<string> next;
            for (auto& w : current) dict.erase(w);
            for (auto& w : current) {
                string s = w;
                for (int i = 0; i < s.size(); i++) {
                    char old = s[i];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) continue;
                        s[i] = c;
                        if (dict.count(s)) {
                            if (!visited.count(s)) {
                                visited.insert(s);
                                next.insert(s);
                            }
                            parents[s].push_back(w);
                            if (s == endWord) found = true;
                        }
                    }
                    s[i] = old;
                }
            }
            current = next;
        }
        if (found) {
            vector<string> path{endWord};
            function<void(string&)> dfs = [&](string& w) {
                if (w == beginWord) {
                    res.push_back(vector<string>(path.rbegin(), path.rend()));
                    return;
                }
                for (auto& p : parents[w]) {
                    path.push_back(p);
                    dfs(p);
                    path.pop_back();
                }
            };
            dfs(endWord);
        }
        return res;
    }
};