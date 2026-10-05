class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        long long lo = 1, hi = x / 2, ans = 0;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            long long sq = mid * mid;
            if (sq == x) return (int)mid;
            if (sq < x) {
                ans = mid;
                lo = mid + 1;
            } else hi = mid - 1;
        }
        return (int)ans;
    }
};