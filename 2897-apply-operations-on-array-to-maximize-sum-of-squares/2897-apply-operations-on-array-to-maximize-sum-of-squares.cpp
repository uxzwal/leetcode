class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        vector<int> bits(32, 0);
        for (int x : nums)
            for (int b = 0; b < 32; b++)
                if (x & (1 << b)) bits[b]++;
        long long ans = 0;
        for (int i = 0; i < k; i++) {
            long long val = 0;
            for (int b = 0; b < 32; b++) {
                if (bits[b] > 0) {
                    val |= (1LL << b);
                    bits[b]--;
                }
            }
            ans = (ans + val % MOD * (val % MOD)) % MOD;
        }
        return ans;
    }
};