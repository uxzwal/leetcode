class Solution {
public:
    int numDistinct(string s, string t) {
        int m = s.length();
        int n = t.length();
        
        // dp[j] stores the number of subsequences of s that match t[0...j-1]
        // Using double or unsigned long long prevents overflow during intermediate states
        vector<double> dp(n + 1, 0);
        
        // Base case: 1 way to match an empty string t
        dp[0] = 1;
        
        for (int i = 1; i <= m; i++) {
            // Traverse backwards to use values from the previous row
            for (int j = n; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        return (int)dp[n];
    }
};