class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(s.length() + 1, 0);
        vector<int> last(26, -1);
        
        dp[0] = 1; // Empty subsequence
        
        for (int i = 0; i < s.length(); i++) {
            dp[i+1] = (dp[i] * 2) % MOD;
            
            if (last[s[i] - 'a'] != -1) {
                dp[i+1] = (dp[i+1] - dp[last[s[i] - 'a']] + MOD) % MOD;
            }
            
            last[s[i] - 'a'] = i;
        }
        
        // Subtract empty subsequence
        return (dp[s.length()] - 1 + MOD) % MOD;
    }
};