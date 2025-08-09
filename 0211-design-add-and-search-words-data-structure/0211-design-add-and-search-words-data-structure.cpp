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

class WordDictionary {
    TrieNode* root;

public:
    WordDictionary() { root = new TrieNode('\0'); }

    void addWord(string word) {
        TrieNode* curr = root;
        for (char& ch : word) {
            if (curr->child.count(ch) == 0) {
                curr->child[ch] = new TrieNode(ch);
            }
            curr = curr->child[ch];
        }
        curr->isTerminal = true;
    }

    bool search(string word) { return searchHelper(0, root, word); }

    bool searchHelper(int idx, TrieNode* node, string word) {
        if (idx == word.size())
            return node->isTerminal;

        char ch = word[idx];

        if (ch == '.') {
            for (auto& curr : node->child) {
                if (searchHelper(idx + 1, curr.second, word))
                    return true;
            }
            return false;
        } else {
            if (node->child.count(ch) == 0)
                return false;
            return searchHelper(idx + 1, node->child[ch], word);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */