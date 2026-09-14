class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {
        for (int i = 0; i < n; i++) {
            int k = rowShift[i] % n;
            vector<int> newRow(n);
            for (int j = 0; j < n; j++) {
                newRow[(j - k + n) % n] = grid[i][j];
            }
            grid[i] = newRow;
        }
        
        for (int j = 0; j < n; j++) {
            int k = colShift[j] % n;
            vector<int> newCol(n);
            for (int i = 0; i < n; i++) {
                newCol[(i - k + n) % n] = grid[i][j];
            }
            for (int i = 0; i < n; i++) {
                grid[i][j] = newCol[i];
            }
        }
        
        return grid;
    }
};