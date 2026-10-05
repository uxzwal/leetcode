class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        int n = s.size();
        function<void(int,int,string)> dfs = [&](int i, int part, string cur) {
            if (part == 4 && i == n) { res.push_back(cur); return; }
            if (part == 4 || i == n) return;
            for (int len = 1; len <= 3 && i + len <= n; len++) {
                string seg = s.substr(i, len);
                if (seg.size() > 1 && seg[0] == '0') break;
                if (stoi(seg) > 255) break;
                string nxt = cur.empty() ? seg : cur + "." + seg;
                dfs(i + len, part + 1, nxt);
            }
        };
        dfs(0, 0, "");
        return res;
    }
};