#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<pair<int, int>>> adj;
    vector<vector<int>> up;
    vector<vector<int>> weight_cnt;
    vector<int> depth;
    int LOG;

    // DFS to calculate depths, binary lifting table, and prefix weight counts
    void dfs(int u, int p, int d, vector<int>& current_weights) {
        depth[u] = d;
        up[u][0] = p;
        weight_cnt[u] = current_weights;

        for (int i = 1; i < LOG; ++i) {
            up[u][i] = up[up[u][i - 1]][i - 1];
        }

        for (auto& edge : adj[u]) {
            int v = edge.first;
            int w = edge.second;
            if (v != p) {
                current_weights[w]++;
                dfs(v, u, d + 1, current_weights);
                current_weights[w]--; // Backtrack
            }
        }
    }

    // Function to find LCA using binary lifting
    int getLCA(int u, int v) {
        if (depth[u] < depth[v]) swap(u, v);

        // Bring both nodes to the same depth level
        for (int i = LOG - 1; i >= 0; --i) {
            if (depth[u] - (1 << i) >= depth[v]) {
                u = up[u][i];
            }
        }

        if (u == v) return u;

        // Lift both nodes simultaneously right below their LCA
        for (int i = LOG - 1; i >= 0; --i) {
            if (up[u][i] != up[v][i]) {
                u = up[u][i];
                v = up[v][i];
            }
        }

        return up[u][0];
    }

public:
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        LOG = log2(n) + 2;
        adj.assign(n, vector<pair<int, int>>());
        up.assign(n, vector<int>(LOG, 0));
        weight_cnt.assign(n, vector<int>(27, 0));
        depth.assign(n, 0);

        for (const auto& edge : edges) {
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }

        vector<int> current_weights(27, 0);
        dfs(0, 0, 0, current_weights);

        vector<int> ans;
        for (const auto& query : queries) {
            int u = query[0];
            int v = query[1];
            int lca = getLCA(u, v);

            int total_edges = depth[u] + depth[v] - 2 * depth[lca];
            int max_freq = 0;

            // Find the most frequent weight on the path between u and v
            for (int w = 1; w <= 26; ++w) {
                int path_freq = weight_cnt[u][w] + weight_cnt[v][w] - 2 * weight_cnt[lca][w];
                max_freq = max(max_freq, path_freq);
            }

            ans.push_back(total_edges - max_freq);
        }

        return ans;
    }
};
