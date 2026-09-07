class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        
        string result;
        int cycleLen = 2 * numRows - 2;
        int n = s.length();
        
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j + i < n; j += cycleLen) {
                result += s[j + i];
                
                // Add middle characters (not first or last row)
                if (i != 0 && i != numRows - 1 && j + cycleLen - i < n) {
                    result += s[j + cycleLen - i];
                }
            }
        }
        
        return result;
    }
};