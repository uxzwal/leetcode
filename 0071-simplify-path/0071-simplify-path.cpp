class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string cur;
        for (int i = 0; i <= (int)path.size(); ++i) {
            if (i == path.size() || path[i] == '/') {
                if (cur == "..") { if (!st.empty()) st.pop_back(); }
                else if (cur!= "" && cur!= ".") st.push_back(cur);
                cur = "";
            } else cur += path[i];
        }
        if (st.empty()) return "/";
        string ans;
        for (auto &d : st) ans += "/" + d;
        return ans;
    }
};