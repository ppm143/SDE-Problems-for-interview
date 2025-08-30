/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans;
        buildString(root, ans);
        return ans;
    }

    void buildString(TreeNode* root, string& ans) {
        if (root == nullptr) {
            ans += "null,";
            return;
        }
        ans += to_string(root->val) + ",";
        buildString(root->left, ans);
        buildString(root->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> trees;
        string s = "";
        for (char& ch : data) {
            if (ch == ',') {
                trees.push(s);
                s = "";
            } else
                s += ch;
        }
        return buildTree(trees);
    }

    TreeNode* buildTree(queue<string>& trees) {
        if (trees.empty()) {
            return nullptr;
        }

        string s = trees.front();
        trees.pop();
        if (s == "null") {
            return nullptr;
        }
        TreeNode* root = new TreeNode(stoi(s));
        root->left = buildTree(trees);
        root->right = buildTree(trees);
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));