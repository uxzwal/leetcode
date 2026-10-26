#include <vector>

class Solution {
public:
    int countIslands(std::vector<std::vector<int>>& grid, int k) {
        int m = grid.size();
        if (m == 0) return 0;
        int n = grid[0].size();
        
        int validIslandCount = 0;

        // Traverse every cell in the grid
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                // If we find an unvisited land cell (> 0)
                if (grid[i][j] > 0) {
                    long long islandSum = 0;
                    // Run DFS to calculate the total sum of this island
                    dfs(grid, i, j, m, n, islandSum);
                    
                    // Check if the total sum is divisible by k
                    if (islandSum % k == 0) {
                        validIslandCount++;
                    }
                }
            }
        }

        return validIslandCount;
    }

private:
    void dfs(std::vector<std::vector<int>>& grid, int r, int c, int m, int n, long long& islandSum) {
        // Base case: check boundaries and if the cell is water (0)
        if (r < 0 || r >= m || c < 0 || c >= n || grid[r][c] == 0) {
            return;
        }

        // Add the current cell's value to the total island sum
        islandSum += grid[r][c];

        // Mark the cell as visited by setting it to 0
        grid[r][c] = 0;

        // Explore all 4 neighbors (Up, Down, Left, Right)
        dfs(grid, r - 1, c, m, n, islandSum); // Up
        dfs(grid, r + 1, c, m, n, islandSum); // Down
        dfs(grid, r, c - 1, m, n, islandSum); // Left
        dfs(grid, r, c + 1, m, n, islandSum); // Right
    }
};
