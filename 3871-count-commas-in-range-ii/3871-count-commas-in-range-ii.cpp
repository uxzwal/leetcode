class Solution {
public:
    long long countCommas(long long n) {
        long long total_commas = 0;
        
        // Define the thresholds where a new comma is introduced
        long long thresholds[] = {
            1000LL,                 // 1st comma (10^3)
            1000000LL,              // 2nd comma (10^6)
            1000000000LL,           // 3rd comma (10^9)
            1000000000000LL,        // 4th comma (10^12)
            1000000000000000LL      // 5th comma (10^15)
        };
        
        for (long long t : thresholds) {
            if (n >= t) {
                total_commas += (n - t + 1);
            } else {
                break; // Since thresholds are increasing, we can stop early
            }
        }
        
        return total_commas;
    }
};