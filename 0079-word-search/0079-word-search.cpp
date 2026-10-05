class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        function<bool(int,int,int)> dfs = [&](int i, int j, int k) -> bool {
            if (k == word.size()) return true;
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j]!= word[k]) return false;
            char tmp = board[i][j];
            board[i][j] = '#';
            bool found = dfs(i+1,j,k+1) || dfs(i-1,j,k+1) || dfs(i,j+1,k+1) || dfs(i,j-1,k+1);
            board[i][j] = tmp;
            return found;
        };
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (board[i][j] == word[0] && dfs(i,j,0)) return true;
        return false;
    }
};