class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        int i = 0, j = 0, match = 0, star = -1;
        
        while (i < m) {
            if (j < n && (p[j] == '?' || p[j] == s[i])) {
                i++;
                j++;
            } else if (j < n && p[j] == '*') {
                star = j;
                match = i;
                j++;
            } else if (star != -1) {
                j = star + 1;
                match++;
                i = match;
            } else {
                return false;
            }
        }
        
        while (j < n && p[j] == '*') {
            j++;
        }
        
        return j == n;
    }
};