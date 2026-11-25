class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t MOD1 = 1000000007ULL;
        const uint64_t MOD2 = 1000000009ULL;
        const uint64_t BASE1 = 1315423911ULL % MOD1;
        const uint64_t BASE2 = 2654435761ULL % MOD2;

        vector<uint64_t> p1(n + 1, 1), p2(n + 1, 1);
        vector<uint64_t> h1(n + 1, 0), h2(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            p1[i + 1] = (p1[i] * BASE1) % MOD1;
            p2[i + 1] = (p2[i] * BASE2) % MOD2;
            h1[i + 1] = (h1[i] * BASE1 + nums[i]) % MOD1;
            h2[i + 1] = (h2[i] * BASE2 + nums[i]) % MOD2;
        }

        auto hasUnique = [&](int len) -> bool {
            int m = n - len + 1;
            vector<uint64_t> hashes(m);
            for (int i = 0; i < m; ++i) {
                uint64_t val1 = (h1[i + len] + MOD1 - (h1[i] * p1[len]) % MOD1) % MOD1;
                uint64_t val2 = (h2[i + len] + MOD2 - (h2[i] * p2[len]) % MOD2) % MOD2;
                hashes[i] = (val1 << 32) | val2;
            }
            sort(hashes.begin(), hashes.end());
            for (int i = 0; i < m; ++i) {
                bool leftSame = (i > 0 && hashes[i] == hashes[i - 1]);
                bool rightSame = (i + 1 < m && hashes[i] == hashes[i + 1]);
                if (!leftSame && !rightSame) return true;
            }
            return false;
        };

        int low = 1, high = n, ans = n;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (hasUnique(mid)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        return ans;
    }
};
