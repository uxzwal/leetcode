class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        for (int i = 0; i <= n; i++) dp[i] = i - 1;
        for (int c = 0; c < n; c++) {
            for (int l = c, r = c; l >= 0 && r < n && s[l] == s[r]; l--, r++)
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
            for (int l = c, r = c + 1; l >= 0 && r < n && s[l] == s[r]; l--, r++)
                dp[r + 1] = min(dp[r + 1], dp[l] + 1);
        }
        return dp[n];
    }
};