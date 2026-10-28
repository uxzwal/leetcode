#include <vector>
#include <algorithm>

class Solution {
public:
    int minCost(std::vector<std::vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        // dp[i][j] stores all unique reachable XOR values at cell (i, j)
        std::vector<std::vector<std::vector<int>>> dp(m, std::vector<std::vector<int>>(n));
        
        // Base case: starting cell
        dp[0][0] = {grid[0][0]};
        
        for (int i = 0; i < m; ++i) {
            for (int i_j = 0; i_j < n; ++i_j) {
                if (i == 0 && i_j == 0) continue;
                
                std::vector<int>& current_cell_xors = dp[i][i_j];
                
                // Coming from the top cell (i - 1, i_j)
                if (i > 0) {
                    for (int val : dp[i - 1][i_j]) {
                        current_cell_xors.push_back(val ^ grid[i][i_j]);
                    }
                }
                
                // Coming from the left cell (i, i_j - 1)
                if (i_j > 0) {
                    for (int val : dp[i][i_j - 1]) {
                        current_cell_xors.push_back(val ^ grid[i][i_j]);
                    }
                }
                
                // Remove duplicates to keep the state space small and fast
                std::sort(current_cell_xors.begin(), current_cell_xors.end());
                current_cell_xors.erase(std::unique(current_cell_xors.begin(), current_cell_xors.end()), current_cell_xors.end());
            }
        }
        
        // The first element in the sorted unique array for the bottom-right cell will be the minimum
        return dp[m - 1][n - 1][0];
    }
};