#include <vector>
#include <string>

using namespace std;

class Solution {
    int n;
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;
    
    // Segment Tree to store the bitmask of character parities
    vector<int> segTree;

    // Heavy-Light Decomposition: First pass to find sizes, depths, and heavy edges
    int dfs_heavy(int v, int p, int d) {
        parent[v] = p;
        depth[v] = d;
        int size = 1;
        int max_c_size = 0;
        for (int c : adj[v]) {
            if (c != p) {
                int c_size = dfs_heavy(c, v, d + 1);
                size += c_size;
                if (c_size > max_c_size) {
                    max_c_size = c_size;
                    heavy[v] = c;
                }
            }
        }
        return size;
    }

    // Heavy-Light Decomposition: Second pass to assign head and segment tree positions
    void dfs_decompose(int v, int h) {
        head[v] = h;
        pos[v] = ++cur_pos;
        if (heavy[v] != -1) {
            dfs_decompose(heavy[v], h);
        }
        for (int c : adj[v]) {
            if (c != parent[v] && c != heavy[v]) {
                dfs_decompose(c, c);
            }
        }
    }

    // Segment Tree Point Update
    void updateSegTree(int node, int start, int end, int idx, int val) {
        if (start == end) {
            segTree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid) {
            updateSegTree(2 * node, start, mid, idx, val);
        } else {
            updateSegTree(2 * node + 1, mid + 1, end, idx, val);
        }
        segTree[node] = segTree[2 * node] ^ segTree[2 * node + 1];
    }

    // Segment Tree Range Query (returns XOR sum of masks)
    int querySegTree(int node, int start, int end, int l, int r) {
        if (r < start || end < l) return 0;
        if (l <= start && end <= r) return segTree[node];
        int mid = (start + end) / 2;
        return querySegTree(2 * node, start, mid, l, r) ^ 
               querySegTree(2 * node + 1, mid + 1, end, l, r);
    }

    // Query the XOR path between two nodes in the tree
    int queryPath(int u, int v) {
        int res = 0;
        while (head[u] != head[v]) {
            if (depth[head[u]] > depth[head[v]]) swap(u, v);
            res ^= querySegTree(1, 1, n, pos[head[v]], pos[v]);
            v = parent[head[v]];
        }
        if (depth[u] > depth[v]) swap(u, v);
        res ^= querySegTree(1, 1, n, pos[u], pos[v]);
        return res;
    }

public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        this->n = n;
        adj.assign(n, vector<int>());
        parent.assign(n, 0);
        depth.assign(n, 0);
        heavy.assign(n, -1);
        head.assign(n, 0);
        pos.assign(n, 0);
        cur_pos = 0;
        segTree.assign(4 * n + 1, 0);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        // Initialize Heavy-Light Decomposition
        dfs_heavy(0, -1, 0);
        dfs_decompose(0, 0);

        // Populate Segment Tree with initial character masks
        for (int i = 0; i < n; ++i) {
            int mask = 1 << (s[i] - 'a');
            updateSegTree(1, 1, n, pos[i], mask);
        }

        vector<bool> ans;
        for (const string& q : queries) {
            if (q[0] == 'u') {
                // Parse update query format: "update u c"
                int u = 0;
                int i = 7;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                char c = q[i + 1];
                int mask = 1 << (c - 'a');
                updateSegTree(1, 1, n, pos[u], mask);
            } else {
                // Parse range query format: "query u v"
                int u = 0, v = 0;
                int i = 6;
                while (q[i] != ' ') {
                    u = u * 10 + (q[i] - '0');
                    i++;
                }
                i++; // Skip space
                while (i < q.size()) {
                    v = v * 10 + (q[i] - '0');
                    i++;
                }
                
                int pathMask = queryPath(u, v);
                // Valid if mask is 0 or has exactly one bit set (power of 2 check)
                ans.push_back((pathMask & (pathMask - 1)) == 0);
            }
        }

        return ans;
    }
};
