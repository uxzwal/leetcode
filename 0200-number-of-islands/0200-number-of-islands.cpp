#include <vector>

using namespace std;

class Solution {
private:
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size(), n = grid[0].size();
        if (r < 0 || c < 0 || r >= m || c >= n || grid[r][c] == '0') return;
        grid[r][c] = '0';
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size(), n = grid[0].size(), islands = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == '1') {
                    islands++;
                    dfs(grid, i, j);
                }
            }
        }
        return islands;
    }
};
