class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        // Transform string to handle even length palindromes
        string transformed = "#";
        for (char c : s) {
            transformed += c;
            transformed += "#";
        }
        
        int n = transformed.length();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        int maxLen = 0, maxCenter = 0;
        
        for (int i = 0; i < n; i++) {
            if (i < right) {
                int mirror = 2 * center - i;
                p[i] = min(right - i, p[mirror]);
            }
            
            // Expand around center i
            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
                   transformed[i - p[i] - 1] == transformed[i + p[i] + 1]) {
                p[i]++;
            }
            
            // Update center and right boundary
            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
            
            // Update max palindrome
            if (p[i] > maxLen) {
                maxLen = p[i];
                maxCenter = i;
            }
        }
        
        int start = (maxCenter - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};