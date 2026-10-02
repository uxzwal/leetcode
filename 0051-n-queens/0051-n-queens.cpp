class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> col(n, false), diag(2 * n, false), antiDiag(2 * n, false);
        backtrack(0, n, board, col, diag, antiDiag, res);
        return res;
    }

    void backtrack(int row, int n, vector<string>& board,
                   vector<bool>& col, vector<bool>& diag,
                   vector<bool>& antiDiag, vector<vector<string>>& res) {
        if (row == n) {
            res.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            if (col[c] || diag[row + c] || antiDiag[row - c + n]) continue;
            board[row][c] = 'Q';
            col[c] = diag[row + c] = antiDiag[row - c + n] = true;
            backtrack(row + 1, n, board, col, diag, antiDiag, res);
            board[row][c] = '.';
            col[c] = diag[row + c] = antiDiag[row - c + n] = false;
        }
    }
};