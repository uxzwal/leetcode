class Solution {
public:
    double myPow(double x, int n) {
        long long N = n;
        long double base = x;
        if (N < 0) {
            base = 1.0L / base;
            N = -N;
        }
        long double res = 1.0L;
        while (N > 0) {
            if (N & 1LL) res *= base;
            base *= base;
            N >>= 1;
        }
        return (double)res;
    }
};