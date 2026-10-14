class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        unordered_map<Node*, Node*> mp;
        function<Node*(Node*)> dfs = [&](Node* n) -> Node* {
            if (mp.count(n)) return mp[n];
            Node* copy = new Node(n->val);
            mp[n] = copy;
            for (Node* nei : n->neighbors) copy->neighbors.push_back(dfs(nei));
            return copy;
        };
        return dfs(node);
    }
};