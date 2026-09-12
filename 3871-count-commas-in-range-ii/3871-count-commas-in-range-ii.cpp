class Solution {
public:
    long long countCommas(long long n) {
        long long ans = 0;
        
        // {lower bound, commas}
        // 10^3 -> 1 comma, 10^6 -> 2 commas, 10^9 -> 3 commas,
        // 10^12 -> 4 commas, 10^15 -> 5 commas
        vector<pair<long long,long long>> levels = {
            {1000LL, 1},
            {1000000LL, 2},
            {1000000000LL, 3},
            {1000000000000LL, 4},
            {1000000000000000LL, 5}
        };
        
        for (int i = 0; i < (int)levels.size(); i++) {
            long long lo = levels[i].first;
            long long c  = levels[i].second;
            if (n < lo) break;
            
            long long hi = (i + 1 < (int)levels.size()) 
                           ? levels[i+1].first - 1 
                           : n;  // last level: up to n
            hi = min(hi, n);
            
            long long cnt = hi - lo + 1;
            ans += cnt * c;
        }
        
        return ans;
    }
};