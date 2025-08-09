class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> child;
    string word;
    bool isTerminal;

    TrieNode(char ch) {
        this->data = ch;
        this->isTerminal = false;
    }

    void addWord(string word) {
        TrieNode* curr = this;
        for (char& ch : word) {
            if (!curr->child.count(ch)) {
                curr->child[ch] = new TrieNode(ch);
            }
            curr = curr->child[ch];
        }
        curr->isTerminal = true;
        curr->word = word;
    }
};
class Solution {
    void solve(int x, int y, TrieNode* node, vector<vector<char>>& board,
               unordered_set<string>& ans) {
        if (x < 0 or y < 0 or x >= board.size() or y >= board[0].size() or
            board[x][y] == '#' or !node->child.count(board[x][y]))
            return;

        char ch = board[x][y];
        board[x][y] = '#';
        node = node->child[ch];

        if (node->isTerminal) {
            ans.insert(node->word);
        }

        solve(x + 1, y, node, board, ans);
        solve(x, y + 1, node, board, ans);
        solve(x - 1, y, node, board, ans);
        solve(x, y - 1, node, board, ans);

        board[x][y] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        int n = board.size();
        int m = board[0].size();

        TrieNode* root = new TrieNode('\0');
        for (string& word : words) {
            root->addWord(word);
        }
        unordered_set<string> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                solve(i, j, root, board, ans);
            }
        }
        return vector<string>(ans.begin(), ans.end());
    }
};