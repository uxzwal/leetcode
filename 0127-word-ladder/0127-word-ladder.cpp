class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (!dict.count(endWord)) return 0;
        queue<string> q;
        q.push(beginWord);
        int level = 1;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string w = q.front(); q.pop();
                if (w == endWord) return level;
                for (int j = 0; j < w.size(); j++) {
                    char old = w[j];
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (c == old) continue;
                        w[j] = c;
                        if (dict.count(w)) {
                            q.push(w);
                            dict.erase(w);
                        }
                    }
                    w[j] = old;
                }
            }
            level++;
        }
        return 0;
    }
};