class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        // Initialize DP array with the values of the bottom-most row
        vector<int> dp = triangle[n - 1];
        
        // Process upward from the second-to-last row down to the top row
        for (int i = n - 2; i >= 0; --i) {
            for (int j = 0; j <= i; ++j) {
                // The minimum path from current node is its value plus 
                // the minimum of the two adjacent choices from the row below
                dp[j] = triangle[i][j] + min(dp[j], dp[j + 1]);
            }
        }
        
        // The top element now stores the total minimum path sum
        return dp[0];
    }
};
