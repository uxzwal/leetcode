class Solution {
public:
    unordered_map<string, bool> memo;
    bool isScramble(string s1, string s2) {
        if (s1 == s2) return true;
        if (s1.size() != s2.size()) return false;
        string key = s1 + "#" + s2;
        if (memo.count(key)) return memo[key];
        int n = s1.size();
        int cnt[26] = {0};
        for (int i = 0; i < n; i++) { cnt[s1[i]-'a']++; cnt[s2[i]-'a']--; }
        for (int i = 0; i < 26; i++) if (cnt[i]) return memo[key] = false;
        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0,i), s2.substr(0,i)) &&
                isScramble(s1.substr(i), s2.substr(i)))
                return memo[key] = true;
            if (isScramble(s1.substr(0,i), s2.substr(n-i)) &&
                isScramble(s1.substr(i), s2.substr(0,n-i)))
                return memo[key] = true;
        }
        return memo[key] = false;
    }
};