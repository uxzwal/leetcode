class Solution {
public:
    int scoreOfParentheses(string s) {
        int ans = 0;
        int bal = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (s[i] == '(') bal++;
            else {
                bal--;
                if (s[i-1] == '(') ans += 1 << bal;
            }
        }
        return ans;
    }
};