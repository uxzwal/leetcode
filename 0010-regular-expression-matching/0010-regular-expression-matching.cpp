class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.length(), n = p.length();
        // memo[i][j]: -1 = unvisited, 0 = false, 1 = true
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        return dfs(s, p, 0, 0, memo);
    }
    
private:
    bool dfs(string& s, string& p, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j] == 1;
        
        bool result;
        if (j == p.length()) {
            result = (i == s.length());
        } else {
            bool firstMatch = (i < s.length() && 
                              (p[j] == '.' || p[j] == s[i]));
            
            if (j + 1 < p.length() && p[j+1] == '*') {
                // '*' matches zero OR one+ of preceding element
                result = dfs(s, p, i, j + 2, memo) || 
                        (firstMatch && dfs(s, p, i + 1, j, memo));
            } else {
                result = firstMatch && dfs(s, p, i + 1, j + 1, memo);
            }
        }
        
        memo[i][j] = result ? 1 : 0;
        return result;
    }
};