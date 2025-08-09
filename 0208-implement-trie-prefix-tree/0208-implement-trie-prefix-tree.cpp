class TrieNode {
public:
    char data;
    unordered_map<char, TrieNode*> child;
    bool isTerminal;
    TrieNode(char data) {
        this->data = data;
        this->isTerminal = false;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() { root = new TrieNode('\0'); }

    void insert(string word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            if (curr->child.count(ch) == 0)
                curr->child[ch] = new TrieNode(ch);
            curr = curr->child[ch];
        }
        curr->isTerminal = true;
    }

    bool search(string word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            if (curr->child.count(ch) == 0)
                return false;
            curr = curr->child[ch];
        }
        return curr->isTerminal;
    }

    bool startsWith(string prefix) {
        TrieNode* curr = root;
        for (char& ch : prefix) {
            if (curr->child.count(ch) == 0)
                return false;
            curr = curr->child[ch];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */