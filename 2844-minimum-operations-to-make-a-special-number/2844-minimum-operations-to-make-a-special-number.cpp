class Solution {
public:
    int minimumOperations(string num) {
        int n = num.length();
        bool foundZero = false;
        bool foundFive = false;
        
        // Traverse backwards from the end of the string
        for (int i = n - 1; i >= 0; --i) {
            // Case 1: Looking for combinations ending with '0' -> "00" or "50"
            if (foundZero) {
                if (num[i] == '0' || num[i] == '5') {
                    // Total length - index of first digit - 2 (the two digits we keep)
                    return n - i - 2; 
                }
            }
            
            // Case 2: Looking for combinations ending with '5' -> "25" or "75"
            if (foundFive) {
                if (num[i] == '2' || num[i] == '7') {
                    return n - i - 2;
                }
            }
            
            // Mark if we see a '0' or '5' for future matches
            if (num[i] == '0') foundZero = true;
            if (num[i] == '5') foundFive = true;
        }
        
        // Edge case: If no pairs were found, but we saw a '0', we can reduce everything else to just "0"
        if (foundZero) {
            return n - 1;
        }
        
        // If nothing else works, we have to delete all characters to make the value 0
        return n;
    }
};
