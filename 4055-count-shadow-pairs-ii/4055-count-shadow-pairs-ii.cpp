class Fenwick {
public:
    vector<int> tree;
    int n;

    Fenwick(int n) : tree(n + 1, 0), n(n) {}

    void update(int i, int delta) {
        for (; i <= n; i += i & -i) tree[i] += delta;
    }

    int query(int i) {
        int s = 0;
        for (; i > 0; i -= i & -i) s += tree[i];
        return s;
    }

    int query(int l, int r) {
        if (l > r) return 0;
        return query(r) - query(l - 1);
    }
};

class Solution {
public:
    int shadowPairs(vector<int>& nums) {
        int n = nums.size();

        const long long INF = 2000000010LL;
        const long long NINF = -2000000010LL;

        function<long long(int, int)> solve = [&](int L, int R) -> long long {
            if (R - L <= 1) return 0;

            int mid = (L + R) / 2;
            long long res = solve(L, mid) + solve(mid, R);

            vector<long long> b(mid - L, INF);
            set<int> st1;

            for (int i = mid - 1; i >= L; --i) {
                auto it = st1.upper_bound(nums[i]);
                if (it != st1.end()) b[i - L] = *it;
                st1.insert(nums[i]);
            }

            vector<long long> c(R - mid, NINF);
            set<int> st2;

            for (int j = mid; j < R; ++j) {
                auto it = st2.lower_bound(nums[j]);
                if (it != st2.begin()) {
                    --it;
                    c[j - mid] = *it;
                }
                st2.insert(nums[j]);
            }

            vector<int> coords;
            coords.reserve(mid - L);

            for (int i = L; i < mid; ++i) {
                if ((long long)nums[i] + 1 < b[i - L]) {
                    coords.push_back(nums[i]);
                }
            }

            sort(coords.begin(), coords.end());
            coords.erase(unique(coords.begin(), coords.end()), coords.end());

            Fenwick ft(coords.size());

            auto rankOf = [&](int x) {
                return int(lower_bound(coords.begin(), coords.end(), x) - coords.begin()) + 1;
            };

            struct Event {
                long long pos;
                int type;
                int idx;
            };

            vector<Event> events;
            events.reserve((mid - L) * 2 + (R - mid));

            for (int i = L; i < mid; ++i) {
                long long addPos = (long long)nums[i] + 1;
                long long removePos = b[i - L] + 1;

                if (addPos < removePos) {
                    events.push_back({addPos, 0, i});
                    events.push_back({removePos, 1, i});
                }
            }

            for (int j = mid; j < R; ++j) {
                events.push_back({nums[j], 2, j});
            }

            sort(events.begin(), events.end(), [](const Event& a, const Event& b) {
                if (a.pos != b.pos) return a.pos < b.pos;
                return a.type < b.type;
            });

            long long cross = 0;

            for (auto& e : events) {
                if (e.type == 0) {
                    ft.update(rankOf(nums[e.idx]), 1);
                } else if (e.type == 1) {
                    ft.update(rankOf(nums[e.idx]), -1);
                } else {
                    long long cj = c[e.idx - mid];

                    int low;
                    if (cj == NINF) {
                        low = 1;
                    } else {
                        low = int(lower_bound(coords.begin(), coords.end(), cj) - coords.begin()) + 1;
                    }

                    cross += ft.query(low, (int)coords.size());
                }
            }

            return res + cross;
        };

        return (int)solve(0, n);
    }
};