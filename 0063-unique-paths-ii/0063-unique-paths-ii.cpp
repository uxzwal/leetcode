class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        // If the starting cell has an obstacle, there are no paths
        if (obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        // Create a 1D DP array of size n, initialized to 0
        vector<int> dp(n, 0);
        
        // Initialize the first column (dp[0] corresponds to column 0)
        dp[0] = 1;
        
        // Initialize the first row
        for (int j = 1; j < n; ++j) {
            // If there's an obstacle, paths become 0. Otherwise, it takes the value from the left.
            if (obstacleGrid[0][j] == 1) {
                dp[j] = 0;
            } else {
                dp[j] = dp[j - 1];
            }
        }
        
        // Iterate through the rest of the grid starting from the second row
        for (int i = 1; i < m; ++i) {
            // Check the first column of the current row
            if (obstacleGrid[i][0] == 1) {
                dp[0] = 0;
            }
            
            for (int j = 1; j < n; ++j) {
                if (obstacleGrid[i][j] == 1) {
                    // If there's an obstacle, no paths can go through here
                    dp[j] = 0;
                } else {
                    // Paths from above (dp[j]) + paths from left (dp[j-1])
                    dp[j] = dp[j] + dp[j - 1];
                }
            }
        }
        
        // The last element holds the number of unique paths to the bottom-right corner
        return dp[n - 1];
    }
};