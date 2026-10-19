#include <vector>
#include <algorithm>

class Solution {
public:
    int calculateMinimumHP(std::vector<std::vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        
        // dp grid initialized to a large value (infinity)
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 1e9));
        
        // Base cases for boundary conditions (just outside the princess room)
        dp[m][n - 1] = 1;
        dp[m - 1][n] = 1;
        
        // Fill the DP table bottom-up
        for (int i = m - 1; i >= 0; --i) {
            for (int j = n - 1; j >= 0; --j) {
                int min_health_needed = std::min(dp[i + 1][j], dp[i][j + 1]) - dungeon[i][j];
                
                // Knight must always have at least 1 HP
                dp[i][j] = std::max(1, min_health_needed);
            }
        }
        
        return dp[0][0];
    }
};
