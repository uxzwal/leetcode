class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> roman = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int result = 0;
        int n = s.length();
        
        for (int i = 0; i < n; i++) {
            int current = roman[s[i]];
            
            // If current value is less than next value, subtract it
            if (i + 1 < n && current < roman[s[i + 1]]) {
                result -= current;
            } else {
                result += current;
            }
        }
        
        return result;
    }
};