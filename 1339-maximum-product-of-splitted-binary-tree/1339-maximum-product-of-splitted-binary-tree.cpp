#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    long long getSubtreeSums(TreeNode* node, vector<long long>& sums) {
        if (!node) return 0;
        long long curr_sum = node->val + getSubtreeSums(node->left, sums) + getSubtreeSums(node->right, sums);
        sums.push_back(curr_sum);
        return curr_sum;
    }

public:
    int maxProduct(TreeNode* root) {
        vector<long long> sums;
        long long total_sum = getSubtreeSums(root, sums);
        long long max_prod = 0;
        const int MOD = 1e9 + 7;

        for (long long s : sums) {
            max_prod = max(max_prod, s * (total_sum - s));
        }

        return max_prod % MOD;
    }
};
