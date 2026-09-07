class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        vector<string> rows(numRows);
        int i = 0;
        
        while (i < s.length()) {
            // Going down
            for (int j = 0; j < numRows && i < s.length(); j++) {
                rows[j] += s[i++];
            }
            
            // Going up diagonally
            for (int j = numRows - 2; j > 0 && i < s.length(); j--) {
                rows[j] += s[i++];
            }
        }
        
        string result;
        for (string row : rows) {
            result += row;
        }
        
        return result;
    }
};