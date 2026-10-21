#include <string>
#include <algorithm>

class Solution {
public:
    int minOperations(std::string s) {
        int n = s.size();
        
        // Case 0: Check if already sorted
        bool sorted = true;
        for (int i = 1; i < n; ++i) {
            if (s[i] < s[i - 1]) {
                sorted = false;
                break;
            }
        }
        if (sorted) {
            return 0;
        }
        
        // Case -1: Cannot sort an unsorted string of length 2
        if (n == 2) {
            return -1;
        }
        
        // Find the absolute minimum and maximum characters
        char mn = *std::min_element(s.begin(), s.end());
        char mx = *std::max_element(s.begin(), s.end());
        
        // Case 1: Minimum character is already at the start OR Maximum character is at the end
        if (s[0] == mn || s[n - 1] == mx) {
            return 1;
        }
        
        // Case 2: If the minimum or maximum element is accessible anywhere in the middle
        for (int i = 1; i < n - 1; ++i) {
            if (s[i] == mn || s[i] == mx) {
                return 2;
            }
        }
        
        // Case 3: Absolute maximum is exclusively at index 0 AND absolute minimum is exclusively at the end
        return 3;
    }
};