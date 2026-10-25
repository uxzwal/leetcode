class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        
        // DFS helper to flood fill land (0s) into water (1s)
        auto dfs = [&](auto self, int r, int c) -> void {
            if (r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != 0) {
                return;
            }
            grid[r][c] = 1; // Mark as visited
            self(self, r + 1, c);
            self(self, r - 1, c);
            self(self, r, c + 1);
            self(self, r, c - 1);
        };
        
        // Step 1: Remove all islands connected to the boundary edges
        for (int i = 0; i < rows; ++i) {
            dfs(dfs, i, 0);            // Left boundary
            dfs(dfs, i, cols - 1);     // Right boundary
        }
        for (int j = 0; j < cols; ++j) {
            dfs(dfs, 0, j);            // Top boundary
            dfs(dfs, rows - 1, j);     // Bottom boundary
        }
        
        // Step 2: Count the remaining closed islands
        int closedIslandsCount = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == 0) {
                    closedIslandsCount++;
                    dfs(dfs, i, j); // Sink the counted closed island
                }
            }
        }
        
        return closedIslandsCount;
    }
};
