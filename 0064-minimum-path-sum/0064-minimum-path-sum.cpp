class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // Create a 1D DP array of size n
        vector<int> dp(n, 0);
        
        // Initialize the first cell
        dp[0] = grid[0][0];
        
        // Initialize the first row
        // The only way to reach cells in the first row is by moving right
        for (int j = 1; j < n; ++j) {
            dp[j] = dp[j - 1] + grid[0][j];
        }
        
        // Iterate through the rest of the grid starting from the second row
        for (int i = 1; i < m; ++i) {
            // Update the first column of the current row
            // The only way to reach cells in the first column is by moving down
            dp[0] = dp[0] + grid[i][0];
            
            for (int j = 1; j < n; ++j) {
                // For each cell, the minimum cost is the cell's value plus
                // the minimum of the path coming from above (dp[j]) or from the left (dp[j-1])
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }
        
        // The last element holds the minimum path sum to the bottom-right corner
        return dp[n - 1];
    }
};