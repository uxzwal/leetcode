#include <vector>
#include <utility>

using namespace std;

class Solution {
    int m, n;
    const int MOD = 1e9 + 7;
    // memo[r][c][d] stores encoded landing position or status:
    // -2: unvisited, -1: out of bounds/invalid
    // >= 0: encoded as (r * 1000 + c)
    int memo[501][501][2];

    pair<int, int> get_next(int r, int c, int d, const vector<vector<int>>& grid) {
        if (memo[r][c][d] != -2) {
            if (memo[r][c][d] == -1) return {-1, -1};
            return {memo[r][c][d] / 1000, memo[r][c][d] % 1000};
        }

        pair<int, int> res = {-1, -1};
        if (d == 0) { // Attempting to move RIGHT
            int nr = r, nc = c + 1;
            if (nc >= n) {
                res = {-1, -1};
            } else if (grid[nr][nc] == 0) {
                res = {nr, nc};
            } else { // Hits a mirror -> deflected DOWN from (nr, nc)
                res = get_next(nr, nc, 1, grid);
            }
        } else { // Attempting to move DOWN
            int nr = r + 1, nc = c;
            if (nr >= m) {
                res = {-1, -1};
            } else if (grid[nr][nc] == 0) {
                res = {nr, nc};
            } else { // Hits a mirror -> deflected RIGHT from (nr, nc)
                res = get_next(nr, nc, 0, grid);
            }
        }

        if (res.first == -1) {
            memo[r][c][d] = -1;
        } else {
            memo[r][c][d] = res.first * 1000 + res.second;
        }
        return res;
    }

public:
    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        
        // Initialize memoization array for current dimensions
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                memo[i][j][0] = -2;
                memo[i][j][1] = -2;
            }
        }

        // dp[r][c] stores path counts to each empty cell
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = 1;

        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (dp[r][c] == 0 || grid[r][c] == 1) continue;

                // Push transitions in both directions: 0 = Right, 1 = Down
                for (int d = 0; d < 2; ++d) {
                    pair<int, int> nxt = get_next(r, c, d, grid);
                    if (nxt.first != -1) {
                        dp[nxt.first][nxt.second] = (dp[nxt.first][nxt.second] + dp[r][c]) % MOD;
                    }
                }
            }
        }

        return dp[m - 1][n - 1];
    }
};
