class Solution {
public:
    int sumNumbers(TreeNode* root) {
        function<int(TreeNode*, int)> dfs = [&](TreeNode* node, int cur) -> int {
            if (!node) return 0;
            cur = cur * 10 + node->val;
            if (!node->left && !node->right) return cur;
            return dfs(node->left, cur) + dfs(node->right, cur);
        };
        return dfs(root, 0);
    }
};