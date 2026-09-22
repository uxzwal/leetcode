class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> res;
        
        // Segment tree node stores:
        // pre[r] : count of prefixes (from left of segment) with product % k == r
        // suf[r] : count of suffixes (to right of segment) with product % k == r
        // all    : count of all subarrays with product % k == r (not needed here, but keeping structure)
        // We only need suffixes of the range [start, n-1] in the query.
        // A suffix of [start, n-1] when combined via tree = suffix of right part * whole left part + suffix of left part
        
        struct Node {
            long long cnt[5]; // suffix counts
            int prod;
        };
        
        vector<Node> tree(4 * n);
        
        auto pull = [&](int node) {
            int l = 2 * node, r = 2 * node + 1;
            tree[node].prod = (1LL * tree[l].prod * tree[r].prod) % k;
            for (int i = 0; i < k; i++) tree[node].cnt[i] = tree[l].cnt[i];
            for (int i = 0; i < k; i++) {
                if (tree[r].cnt[i]) {
                    int nr = (int)((1LL * i * tree[l].prod) % k);
                    tree[node].cnt[nr] += tree[r].cnt[i];
                }
            }
        };
        
        function<void(int, int, int)> build = [&](int node, int l, int r) {
            if (l == r) {
                int v = nums[l] % k;
                for (int i = 0; i < k; i++) tree[node].cnt[i] = 0;
                tree[node].cnt[v] = 1;
                tree[node].prod = v;
                return;
            }
            int mid = (l + r) >> 1;
            build(2 * node, l, mid);
            build(2 * node + 1, mid + 1, r);
            pull(node);
        };
        
        function<void(int, int, int, int, int)> update = [&](int node, int l, int r, int idx, int val) {
            if (l == r) {
                int v = val % k;
                for (int i = 0; i < k; i++) tree[node].cnt[i] = 0;
                tree[node].cnt[v] = 1;
                tree[node].prod = v;
                return;
            }
            int mid = (l + r) >> 1;
            if (idx <= mid) update(2 * node, l, mid, idx, val);
            else update(2 * node + 1, mid + 1, r, idx, val);
            pull(node);
        };
        
        // Query returns a Node representing the segment [ql, qr]
        function<Node(int, int, int, int, int)> query = [&](int node, int l, int r, int ql, int qr) -> Node {
            if (ql <= l && r <= qr) return tree[node];
            int mid = (l + r) >> 1;
            if (qr <= mid) return query(2 * node, l, mid, ql, qr);
            if (ql > mid) return query(2 * node + 1, mid + 1, r, ql, qr);
            
            Node L = query(2 * node, l, mid, ql, qr);
            Node R = query(2 * node + 1, mid + 1, r, ql, qr);
            Node merged;
            merged.prod = (int)((1LL * L.prod * R.prod) % k);
            for (int i = 0; i < k; i++) merged.cnt[i] = L.cnt[i];
            for (int i = 0; i < k; i++) {
                if (R.cnt[i]) {
                    int nr = (int)((1LL * i * L.prod) % k);
                    merged.cnt[nr] += R.cnt[i];
                }
            }
            return merged;
        };
        
        build(1, 0, n - 1);
        
        for (auto& q : queries) {
            int idx = q[0], val = q[1], start = q[2], x = q[3];
            update(1, 0, n - 1, idx, val);
            nums[idx] = val;
            
            Node ans = query(1, 0, n - 1, start, n - 1);
            res.push_back((int)ans.cnt[x]);
        }
        
        return res;
    }
};