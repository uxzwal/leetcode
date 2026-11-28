#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        vector<int> freq(n + 1, 0);
        long long global_min_price = LLONG_MAX;

        for (const auto& item : items) {
            freq[item[0]]++;
            global_min_price = min(global_min_price, (long long)item[1]);
        }

        vector<int> multiples_cnt(n + 1, 0);
        for (int f = 1; f <= n; ++f) {
            if (freq[f] == 0) continue;
            for (int m = f; m <= n; m += f) {
                multiples_cnt[f] += freq[m];
            }
            multiples_cnt[f]--;
        }

        vector<pair<long long, int>> item_caps;
        for (const auto& item : items) {
            int cap = multiples_cnt[item[0]];
            long long price = item[1];
            if (cap > 0 && price < 2 * global_min_price) {
                item_caps.push_back({price, cap});
            }
        }

        sort(item_caps.begin(), item_caps.end());

        long long rem = budget;
        long long ans = 0;

        for (const auto& [price, cap] : item_caps) {
            if (rem < price) break;
            long long take = min(rem / price, (long long)cap);
            ans += take * 2;
            rem -= take * price;
        }

        if (rem >= global_min_price) {
            ans += rem / global_min_price;
        }

        return ans;
    }
};