class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int left = max(0, dfs(node->left));
            int right = max(0, dfs(node->right));
            ans = max(ans, node->val + left + right);
            return node->val + max(left, right);
        };
        dfs(root);
        return ans;
    }
};