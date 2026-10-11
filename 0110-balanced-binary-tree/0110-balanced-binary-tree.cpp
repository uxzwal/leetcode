class Solution {
public:
    bool isBalanced(TreeNode* root) {
        function<int(TreeNode*)> height = [&](TreeNode* node) -> int {
            if (!node) return 0;
            int left = height(node->left);
            if (left == -1) return -1;
            int right = height(node->right);
            if (right == -1) return -1;
            if (abs(left - right) > 1) return -1;
            return 1 + max(left, right);
        };
        return height(root) != -1;
    }
};