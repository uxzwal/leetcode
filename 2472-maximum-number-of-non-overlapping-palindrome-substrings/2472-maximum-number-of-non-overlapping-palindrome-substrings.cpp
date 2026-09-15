class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for (int i = 0; i < n; i++) dp[i][i] = true;
        for (int i = 0; i < n - 1; i++) dp[i][i + 1] = (s[i] == s[i + 1]);
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i + len - 1 < n; i++) {
                int j = i + len - 1;
                dp[i][j] = (s[i] == s[j]) && dp[i + 1][j - 1];
            }
        }
        vector<int> f(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            f[i] = f[i - 1];
            for (int j = i - k; j >= 0; j--) {
                if (dp[j][i - 1]) {
                    f[i] = max(f[i], f[j] + 1);
                    break;
                }
            }
        }
        return f[n];
    }
};