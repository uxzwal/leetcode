class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* leftmost = root;
        
        // Loop level by level down the tree
        while (leftmost->left != nullptr) {
            Node* curr = leftmost;
            
            // Traverse nodes across the current level
            while (curr != nullptr) {
                // Connection 1: Left child to Right child
                curr->left->next = curr->right;
                
                // Connection 2: Right child to adjacent Left child
                if (curr->next != nullptr) {
                    curr->right->next = curr->next->left;
                }
                
                // Move horizontally along the current level
                curr = curr->next;
            }
            
            // Move vertically to the next level down
            leftmost = leftmost->left;
        }
        
        return root;
    }
};
