class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return nullptr;
        
        Node* curr = root; // Tracks the current node in the current level
        
        while (curr != nullptr) {
            Node dummy(0);      // Dummy node to start the next level's linked list
            Node* tail = &dummy; // Tail pointer to build the next level's connections
            
            // Traverse all nodes horizontally across the current level
            while (curr != nullptr) {
                if (curr->left != nullptr) {
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if (curr->right != nullptr) {
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next; // Move to the adjacent node on the current level
            }
            
            // Move down to the beginning of the next level
            curr = dummy.next;
        }
        
        return root;
    }
};
