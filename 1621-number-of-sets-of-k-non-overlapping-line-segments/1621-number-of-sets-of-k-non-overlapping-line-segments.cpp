class Solution {
public:
    int numberOfSets(int n, int k) {
        const int MOD = 1e9 + 7;
        int N = n + k - 1;
        int R = 2 * k;
        if (R > N) return 0;
        
        // Compute C(N, R) mod MOD
        vector<long long> fact(N + 1, 1), inv(N + 1, 1);
        for (int i = 1; i <= N; i++) fact[i] = fact[i - 1] * i % MOD;
        
        auto power = [&](long long base, long long exp) {
            long long res = 1;
            while (exp) {
                if (exp & 1) res = res * base % MOD;
                base = base * base % MOD;
                exp >>= 1;
            }
            return res;
        };
        
        inv[N] = power(fact[N], MOD - 2);
        for (int i = N - 1; i >= 0; i--) inv[i] = inv[i + 1] * (i + 1) % MOD;
        
        return (int)(fact[N] * inv[R] % MOD * inv[N - R] % MOD);
    }
};