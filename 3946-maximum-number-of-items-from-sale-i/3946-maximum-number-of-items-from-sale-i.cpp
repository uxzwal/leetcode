class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> free_copies(n, 0);
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    free_copies[i]++;
                }
            }
        }
        
        vector<int> dp(budget + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            int cost = items[i][1];
            int val = 1 + free_copies[i];
            for (int b = budget; b >= cost; --b) {
                dp[b] = max(dp[b], dp[b - cost] + val);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            int cost = items[i][1];
            for (int b = cost; b <= budget; ++b) {
                dp[b] = max(dp[b], dp[b - cost] + 1);
            }
        }
        
        int ans = 0;
        for (int b = 0; b <= budget; ++b) {
            ans = max(ans, dp[b]);
        }
        
        return ans;
    }
};
