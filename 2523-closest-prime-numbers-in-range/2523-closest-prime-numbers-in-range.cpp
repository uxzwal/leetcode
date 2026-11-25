class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> isPrime(right + 1, true);
        isPrime[0] = false;
        if (right >= 1) isPrime[1] = false;
        
        for (int i = 2; i * i <= right; ++i) {
            if (isPrime[i]) {
                for (int j = i * i; j <= right; j += i) {
                    isPrime[j] = false;
                }
            }
        }
        
        int prevPrime = -1;
        int minDiff = INT_MAX;
        vector<int> ans = {-1, -1};
        
        for (int i = left; i <= right; ++i) {
            if (isPrime[i]) {
                if (prevPrime != -1 && i - prevPrime < minDiff) {
                    minDiff = i - prevPrime;
                    ans = {prevPrime, i};
                }
                prevPrime = i;
            }
        }
        
        return ans;
    }
};
