class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n);
        for (int i = 0; i < n; i++) diff[i] = abs((long long)nums1[i] - nums2[i]);
        long long total = (long long)k1 + k2;
        long long sum = 0;
        for (auto d : diff) sum += d;
        if (sum <= total) return 0;
        long long lo = 0, hi = 1000000000000LL;
        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;
            long long ops = 0;
            for (auto d : diff) if (d > mid) ops += d - mid;
            if (ops <= total) hi = mid;
            else lo = mid + 1;
        }
        long long ops = 0;
        for (auto d : diff) if (d > lo) ops += d - lo;
        long long rem = total - ops;
        long long ans = 0;
        for (auto d : diff) {
            if (d > lo) ans += lo * lo;
            else ans += d * d;
        }
        ans -= rem * (lo * lo - (lo - 1) * (lo - 1));
        return ans;
    }
};