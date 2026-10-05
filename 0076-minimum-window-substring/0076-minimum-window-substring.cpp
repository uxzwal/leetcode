class Solution {
public:
    string minWindow(string s, string t) {
        if (t.size() > s.size()) return "";
        vector<int> need(128, 0), win(128, 0);
        for (char c : t) need[c]++;
        int required = 0;
        for (int i = 0; i < 128; i++) if (need[i] > 0) required++;

        int formed = 0, l = 0, bestLen = INT_MAX, bestL = 0;
        for (int r = 0; r < (int)s.size(); r++) {
            win[s[r]]++;
            if (need[s[r]] > 0 && win[s[r]] == need[s[r]]) formed++;

            while (formed == required && l <= r) {
                if (r - l + 1 < bestLen) {
                    bestLen = r - l + 1;
                    bestL = l;
                }
                win[s[l]]--;
                if (need[s[l]] > 0 && win[s[l]] < need[s[l]]) formed--;
                l++;
            }
        }
        return bestLen == INT_MAX? "" : s.substr(bestL, bestLen);
    }
};