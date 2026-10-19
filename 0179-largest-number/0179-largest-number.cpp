#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        // 1. Convert all integers to strings
        vector<string> numStrings;
        for (int num : nums) {
            numStrings.push_back(to_string(num));
        }
        
        // 2. Sort strings using the custom comparator
        sort(numStrings.begin(), numStrings.end(), [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        // 3. Handle the edge case where the largest number is "0" (e.g., [0, 0])
        if (numStrings[0] == "0") {
            return "0";
        }
        
        // 4. Concatenate sorted strings to form the largest number
        string largestNum = "";
        for (const string& str : numStrings) {
            largestNum += str;
        }
        
        return largestNum;
    }
};
