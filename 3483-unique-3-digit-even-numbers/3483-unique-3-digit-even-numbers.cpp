class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> uniqueNumbers;
        int n = digits.size();
        
        // Try all combinations of 3 positions
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    // Ensure distinct indices
                    if (i == j || j == k || i == k) continue;
                    
                    // Hundreds digit cannot be 0
                    if (digits[i] == 0) continue;
                    
                    // Units digit must be even
                    if (digits[k] % 2 != 0) continue;
                    
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    uniqueNumbers.insert(num);
                }
            }
        }
        
        return uniqueNumbers.size();
    }
};