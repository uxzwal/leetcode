class Solution {
public:
    int titleToNumber(string columnTitle) {
        long long result = 0; // Use long long to easily prevent any temporary overflow
        
        for (char c : columnTitle) {
            int value = c - 'A' + 1;
            result = result * 26 + value;
        }
        
        return result;
    }
};
