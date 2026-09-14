class Solution {
public:
    long long minOperations(vector<int>& nums) {
        static vector<long long> oddPals  = build(1);
        static vector<long long> evenPals = build(0);
        long long total = 0;
        for (int x : nums) {
            const vector<long long>& v = (x & 1) ? oddPals : evenPals;
            auto it = lower_bound(v.begin(), v.end(), (long long)x);
            long long best = LLONG_MAX;
            if (it != v.end())   best = min(best, (*it - x) / 2);
            if (it != v.begin()) { --it; best = min(best, (x - *it) / 2); }
            total += best;
        }
        return total;
    }

private:
    static vector<long long> build(int parity) {
        vector<long long> res;
        for (int half = 1; half <= 100000; half++) {
            string s = to_string(half);
            string rs = s; reverse(rs.begin(), rs.end());
            long long oddV  = stoll(s + rs.substr(1));
            long long evenV = stoll(s + rs);
            if (oddV  <= 2000000000LL && (oddV  & 1) == parity) res.push_back(oddV);
            if (evenV <= 2000000000LL && (evenV & 1) == parity) res.push_back(evenV);
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};