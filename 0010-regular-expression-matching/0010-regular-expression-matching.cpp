class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // dp[i][j] = whether s[0..i-1] matches p[0..j-1]
        vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
        
        // Empty string matches empty pattern
        dp[0][0] = true;
        
        // Handle patterns like a*, a*b*, a*b*c* matching empty string
        for (int j = 2; j <= n; j++) {
            if (p[j-1] == '*') {
                dp[0][j] = dp[0][j-2];
            }
        }
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (p[j-1] == '*') {
                    // Case 1: '*' matches zero of preceding element
                    dp[i][j] = dp[i][j-2];
                    
                    // Case 2: '*' matches one or more of preceding element
                    if (p[j-2] == '.' || p[j-2] == s[i-1]) {
                        dp[i][j] = dp[i][j] || dp[i-1][j];
                    }
                } else {
                    // Current pattern char matches current string char
                    if (p[j-1] == '.' || p[j-1] == s[i-1]) {
                        dp[i][j] = dp[i-1][j-1];
                    }
                }
            }
        }
        
        return dp[m][n];
    }
};