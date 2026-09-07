class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> lastIndex(128, -1); // ASCII characters
        int maxLength = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            // If character seen before, move start pointer
            if (lastIndex[s[end]] >= start) {
                start = lastIndex[s[end]] + 1;
            }
            
            // Update last occurrence of current character
            lastIndex[s[end]] = end;
            
            // Update max length
            maxLength = max(maxLength, end - start + 1);
        }
        
        return maxLength;
    }
};