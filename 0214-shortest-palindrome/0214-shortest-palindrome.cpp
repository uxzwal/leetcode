#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.length();
        if (n <= 1) return s;

        // Reverse the original string
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());

        // Combine string with a sentinel character '#' to avoid overlap bounds
        string temp = s + "#" + rev_s;
        int m = temp.length();

        // Compute the KMP Lookup (LPS - Longest Prefix Suffix) table
        vector<int> lps(m, 0);
        for (int i = 1; i < m; i++) {
            int j = lps[i - 1];
            while (j > 0 && temp[i] != temp[j]) {
                j = lps[j - 1];
            }
            if (temp[i] == temp[j]) {
                j++;
            }
            lps[i] = j;
        }

        // lps.back() contains the length of the longest palindromic prefix in 's'
        int longest_palindrome_prefix_len = lps.back();

        // The suffix that needs to be reversed and added to the front
        string remain_suffix = s.substr(longest_palindrome_prefix_len);
        reverse(remain_suffix.begin(), remain_suffix.end());

        return remain_suffix + s;
    }
};
