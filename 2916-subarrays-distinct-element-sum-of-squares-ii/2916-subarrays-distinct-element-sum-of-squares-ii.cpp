#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    const int MOD = 1e9 + 7;
    vector<long long> sum_f;
    vector<long long> sum_f2;
    vector<long long> lazy;

    void push(int node, int start, int end) {
        if (lazy[node] == 0) return;
        
        int mid = start + (end - start) / 2;
        int left_child = 2 * node;
        int right_child = 2 * node + 1;
        long long val = lazy[node];

        // Update left child
        long long len_l = mid - start + 1;
        sum_f2[left_child] = (sum_f2[left_child] + 2 * val * sum_f[left_child] + val * val % MOD * len_l) % MOD;
        sum_f[left_child] = (sum_f[left_child] + val * len_l) % MOD;
        lazy[left_child] = (lazy[left_child] + val) % MOD;

        // Update right child
        long long len_r = end - mid;
        sum_f2[right_child] = (sum_f2[right_child] + 2 * val * sum_f[right_child] + val * val % MOD * len_r) % MOD;
        sum_f[right_child] = (sum_f[right_child] + val * len_r) % MOD;
        lazy[right_child] = (lazy[right_child] + val) % MOD;

        lazy[node] = 0;
    }

    void update(int node, int start, int end, int l, int r, long long val) {
        if (r < start || end < l) return;
        if (l <= start && end <= r) {
            long long len = end - start + 1;
            sum_f2[node] = (sum_f2[node] + 2 * val * sum_f[node] + val * val % MOD * len) % MOD;
            sum_f[node] = (sum_f[node] + val * len) % MOD;
            lazy[node] = (lazy[node] + val) % MOD;
            return;
        }
        push(node, start, end);
        int mid = start + (end - start) / 2;
        update(2 * node, start, mid, l, r, val);
        update(2 * node + 1, mid + 1, end, l, r, val);
        
        sum_f[node] = (sum_f[2 * node] + sum_f[2 * node + 1]) % MOD;
        sum_f2[node] = (sum_f2[2 * node] + sum_f2[2 * node + 1]) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        sum_f.assign(4 * n, 0);
        sum_f2.assign(4 * n, 0);
        lazy.assign(4 * n, 0);

        unordered_map<int, int> last_seen;
        long long total_sum = 0;

        for (int j = 0; j < n; ++j) {
            int prev = last_seen.count(nums[j]) ? last_seen[nums[j]] : -1;
            
            // Add 1 to distinct counts for all subarrays starting from index (prev + 1) to j
            update(1, 0, n - 1, prev + 1, j, 1);
            
            // sum_f2[1] holds the sum of squares of distinct counts for all subarrays ending at index j
            total_sum = (total_sum + sum_f2[1]) % MOD;
            
            last_seen[nums[j]] = j;
        }

        return total_sum;
    }
};
