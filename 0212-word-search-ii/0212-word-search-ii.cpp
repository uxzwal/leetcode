#include <vector>
#include <string>

using namespace std;

// A standard Trie structure designed to manage the dictionary efficiently.
struct TrieNode {
    TrieNode* children[26] = {nullptr};
    string word = ""; // Stores the complete word at the leaf node for easy retrieval
};

class Solution {
private:
    void insertWord(TrieNode* root, const string& word) {
        TrieNode* curr = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!curr->children[idx]) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->word = word; // Mark the end of a valid word
    }

    void dfs(vector<vector<char>>& board, int r, int c, TrieNode* node, vector<string>& result) {
        char ch = board[r][c];
        int idx = ch - 'a';
        
        // Base cases: character mismatch or cell already visited ('#')
        if (ch == '#' || !node->children[idx]) return;

        node = node->children[idx];
        
        // Found a matching word
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // De-duplicate so we don't pick the same word twice
        }

        // Mark the current cell as visited
        board[r][c] = '#';

        // Explore all 4 neighbors: Up, Down, Left, Right
        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};
        for (int i = 0; i < 4; ++i) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            if (nr >= 0 && nr < board.size() && nc >= 0 && nc < board[0].size()) {
                dfs(board, nr, nc, node, result);
            }
        }

        // Backtrack: restore the original character
        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (const string& w : words) {
            insertWord(root, w);
        }

        vector<string> result;
        int rows = board.size();
        int cols = board[0].size();

        // Start DFS backtracking from every cell on the board
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                dfs(board, r, c, root, result);
            }
        }

        return result;
    }
};
