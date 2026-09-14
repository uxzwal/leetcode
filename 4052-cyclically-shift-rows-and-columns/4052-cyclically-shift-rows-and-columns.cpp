class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        vector<vector<int>> res(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                int srcRow = (i + colShift[j]) % n;
                int srcCol = (j + rowShift[srcRow]) % n;
                res[i][j] = grid[srcRow][srcCol];
            }
        return res;
    }
};