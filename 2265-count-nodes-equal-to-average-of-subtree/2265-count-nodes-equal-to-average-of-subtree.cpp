/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int averageOfSubtree(TreeNode* root) {
        int count = 0;
        dfs(root, count);
        return count;
    }
    
private:
    // Returns {sum, nodeCount} of subtree
    pair<int, int> dfs(TreeNode* node, int& count) {
        if (!node) return {0, 0};
        
        auto [leftSum, leftCount] = dfs(node->left, count);
        auto [rightSum, rightCount] = dfs(node->right, count);
        
        int totalSum = leftSum + rightSum + node->val;
        int totalCount = leftCount + rightCount + 1;
        
        // Check if node value equals average (floor division)
        if (node->val == totalSum / totalCount) {
            count++;
        }
        
        return {totalSum, totalCount};
    }
};