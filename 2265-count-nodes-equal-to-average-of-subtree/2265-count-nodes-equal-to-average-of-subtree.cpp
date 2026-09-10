class Solution {
public:
    int count = 0;
    
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
    
private:
    pair<int, int> dfs(TreeNode* node) {
        if (!node) return {0, 0};
        
        auto left = dfs(node->left);
        auto right = dfs(node->right);
        
        int sum = left.first + right.first + node->val;
        int nodes = left.second + right.second + 1;
        
        if (node->val == sum / nodes) {
            count++;
        }
        
        return {sum, nodes};
    }
};