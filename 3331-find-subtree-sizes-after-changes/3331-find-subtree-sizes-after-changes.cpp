#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adj(n);
        for (int i = 1; i < n; ++i) {
            adj[parent[i]].push_back(i);
        }

        vector<int> new_parent = parent;
        vector<int> last_seen(26, -1);

        // Step 1: Find the closest matching ancestor for each node
        auto dfs1 = [&](auto& self, int u) -> void {
            int char_idx = s[u] - 'a';
            int prev_ancestor = last_seen[char_idx];
            
            if (prev_ancestor != -1) {
                new_parent[u] = prev_ancestor;
            }
            
            last_seen[char_idx] = u;
            for (int v : adj[u]) {
                self(self, v);
            }
            last_seen[char_idx] = prev_ancestor; // Backtrack
        };

        dfs1(dfs1, 0);

        // Step 2: Rebuild the tree and compute final subtree sizes
        vector<vector<int>> new_adj(n);
        for (int i = 1; i < n; ++i) {
            new_adj[new_parent[i]].push_back(i);
        }

        vector<int> ans(n, 0);
        auto dfs2 = [&](auto& self, int u) -> int {
            int size = 1;
            for (int v : new_adj[u]) {
                size += self(self, v);
            }
            return ans[u] = size;
        };

        dfs2(dfs2, 0);
        return ans;
    }
};
