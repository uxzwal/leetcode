class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        set<string> uniqueNumbers;
        int n = digits.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) continue;
                    if (digits[i] == 0) continue;
                    if (digits[k] % 2 != 0) continue;
                    
                    string num = to_string(digits[i]) + 
                                 to_string(digits[j]) + 
                                 to_string(digits[k]);
                    uniqueNumbers.insert(num);
                }
            }
        }
        
        return uniqueNumbers.size();
    }
};