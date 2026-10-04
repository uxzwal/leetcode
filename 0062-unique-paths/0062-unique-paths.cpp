class Solution {
public:
    int uniquePaths(int m, int n) {
        // Use a 1D array to represent the current row's path counts.
        // We initialize it with 1s because there is exactly 1 way to reach any cell in the first row (by only moving right).
        vector<int> dp(n, 1);
        
        // Iterate through the rows starting from the second row (index 1)
        for (int i = 1; i < m; ++i) {
            // Iterate through the columns starting from the second column (index 1)
            for (int j = 1; j < n; ++j) {
                // The number of paths to the current cell is the sum of:
                // 1. The number of paths from the cell above (which is currently stored in dp[j])
                // 2. The number of paths from the cell to the left (which is the newly updated dp[j-1])
                dp[j] = dp[j] + dp[j - 1];
            }
        }
        
        // The last element of the array holds the number of unique paths to the bottom-right corner
        return dp[n - 1];
    }
};