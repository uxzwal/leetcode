class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {};
        function<vector<TreeNode*>(int,int)> build = [&](int l, int r) {
            vector<TreeNode*> res;
            if (l > r) { res.push_back(nullptr); return res; }
            for (int i = l; i <= r; i++) {
                auto left = build(l, i - 1);
                auto right = build(i + 1, r);
                for (auto L : left) {
                    for (auto R : right) {
                        TreeNode* root = new TreeNode(i, L, R);
                        res.push_back(root);
                    }
                }
            }
            return res;
        };
        return build(1, n);
    }
};