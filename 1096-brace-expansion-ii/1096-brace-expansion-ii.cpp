class Solution {
public:
    vector<string> braceExpansionII(string expression) {
        int i = 0;
        auto result = parse(expression, i);
        vector<string> ans(result.begin(), result.end());
        return ans;
    }
    
private:
    set<string> parse(const string& s, int& i) {
        set<string> res;
        set<string> cur;
        cur.insert("");
        
        while (i < s.size() && s[i] != '}') {
            if (s[i] == '{') {
                i++;
                set<string> inner = parse(s, i);
                i++; // skip '}'
                cur = product(cur, inner);
            } else if (s[i] == ',') {
                res.insert(cur.begin(), cur.end());
                cur = {""};
                i++;
            } else {
                set<string> letter = {string(1, s[i])};
                cur = product(cur, letter);
                i++;
            }
        }
        
        res.insert(cur.begin(), cur.end());
        return res;
    }
    
    set<string> product(const set<string>& a, const set<string>& b) {
        set<string> res;
        for (const auto& x : a) {
            for (const auto& y : b) {
                res.insert(x + y);
            }
        }
        return res;
    }
};