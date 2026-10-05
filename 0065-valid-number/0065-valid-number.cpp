class Solution {
public:
    bool isNumber(string s) {
        int n = s.size();
        int i = 0;
        bool num = false, dot = false, exp = false;
        if (i < n && (s[i] == '+' || s[i] == '-')) i++;
        for (; i < n; i++) {
            char c = s[i];
            if (c >= '0' && c <= '9') {
                num = true;
            } else if (c == '.') {
                if (dot || exp) return false;
                dot = true;
            } else if (c == 'e' || c == 'E') {
                if (exp ||!num) return false;
                exp = true;
                num = false;
                dot = true;
                if (i + 1 < n && (s[i+1] == '+' || s[i+1] == '-')) i++;
            } else {
                return false;
            }
        }
        return num;
    }
};