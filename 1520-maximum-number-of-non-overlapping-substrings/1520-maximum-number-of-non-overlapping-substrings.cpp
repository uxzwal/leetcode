class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> first(26, n), last(26, -1);
        for (int i = 0; i < n; ++i) {
            int c = s[i] - 'a';
            first[c] = min(first[c], i);
            last[c] = max(last[c], i);
        }

        vector<pair<int,int>> intervals;
        for (int c = 0; c < 26; ++c) {
            if (last[c] == -1) continue;
            int l = first[c], r = last[c];
            bool valid = true;
            for (int i = l; i <= r; ++i) {
                int d = s[i] - 'a';
                if (first[d] < l) { valid = false; break; }
                r = max(r, last[d]);
            }
            if (valid) intervals.push_back({l, r});
        }

        sort(intervals.begin(), intervals.end(), [](auto &a, auto &b) {
            return a.second == b.second ? a.first > b.first : a.second < b.second;
        });

        vector<string> res;
        int end = -1;
        for (auto &[l, r] : intervals) {
            if (l > end) {
                res.push_back(s.substr(l, r - l + 1));
                end = r;
            }
        }
        return res;
    }
};