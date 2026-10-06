class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        function<bool(TreeNode*, TreeNode*)> mirror = [&](TreeNode* a, TreeNode* b) {
            if (!a && !b) return true;
            if (!a || !b) return false;
            return a->val == b->val && mirror(a->left, b->right) && mirror(a->right, b->left);
        };
        return mirror(root->left, root->right);
    }
};