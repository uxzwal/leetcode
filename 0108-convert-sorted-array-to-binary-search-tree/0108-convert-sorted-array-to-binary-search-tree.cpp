class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        function<TreeNode*(int,int)> build = [&](int l, int r) -> TreeNode* {
            if (l > r) return nullptr;
            int mid = l + (r - l) / 2;
            TreeNode* node = new TreeNode(nums[mid]);
            node->left = build(l, mid - 1);
            node->right = build(mid + 1, r);
            return node;
        };
        return build(0, nums.size() - 1);
    }
};