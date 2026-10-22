class Solution {
public:
    int countCommas(int n) {
        long long totalCommas = 0;
        
        // Every factor of 1000 adds an additional comma to the formatting
        for (long long i = 1000; i <= n; i *= 1000) {
            totalCommas += (n - i + 1);
        }
        
        return totalCommas;
    }
};