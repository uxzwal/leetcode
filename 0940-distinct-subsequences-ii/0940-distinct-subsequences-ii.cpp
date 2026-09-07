class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        int n = s.length();
        
        // dp[i] = number of distinct non-empty subsequences of s[0...i]
        vector<long long> dp(n);
        
        // Store the last occurrence of each character
        vector<int> last(26, -1);
        
        for (int i = 0; i < n; i++) {
            // Initialize: subsequence containing only current character
            dp[i] = 1;
            
            if (i > 0) {
                // All subsequences from previous state
                // Plus all subsequences from previous state with current char appended
                dp[i] = (dp[i] + 2 * dp[i-1]) % MOD;
            }
            
            // If current character has appeared before, remove duplicates
            int prev = last[s[i] - 'a'];
            if (prev != -1) {
                if (prev == 0) {
                    dp[i] = (dp[i] - 1 + MOD) % MOD;
                } else {
                    dp[i] = (dp[i] - dp[prev-1] - 1 + MOD) % MOD;
                }
            }
            
            // Update last occurrence
            last[s[i] - 'a'] = i;
        }
        
        return dp[n-1];
    }
};