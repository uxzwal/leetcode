class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> idx;
        for (int i = 0; i < inorder.size(); i++) idx[inorder[i]] = i;
        int post = postorder.size() - 1;
        function<TreeNode*(int,int)> build = [&](int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int val = postorder[post--];
            TreeNode* node = new TreeNode(val);
            int mid = idx[val];
            node->right = build(mid + 1, r);
            node->left = build(l, mid - 1);
            return node;
        };
        return build(0, inorder.size() - 1);
    }
};