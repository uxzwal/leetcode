class Solution {
public:
    int totalNQueens(int n) {
        int count = 0;
        vector<bool> col(n, false), diag(2 * n, false), antiDiag(2 * n, false);
        backtrack(0, n, col, diag, antiDiag, count);
        return count;
    }

    void backtrack(int row, int n, vector<bool>& col, vector<bool>& diag,
                   vector<bool>& antiDiag, int& count) {
        if (row == n) {
            count++;
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || diag[row + c] || antiDiag[row - c + n]) continue;
            col[c] = diag[row + c] = antiDiag[row - c + n] = true;
            backtrack(row + 1, n, col, diag, antiDiag, count);
            col[c] = diag[row + c] = antiDiag[row - c + n] = false;
        }
    }
};