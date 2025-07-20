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
        solve(root, ans);
        return ans;
    }

    void solve(TreeNode* root, string& ans) {
        if (root == nullptr) {
            ans += "null,";
            return;
        }
        ans += to_string(root->val);
        ans += ",";

        solve(root->left, ans);
        solve(root->right, ans);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> trees;
        string s;
        stringstream in(data);
        while (getline(in, s, ','))
            trees.push(s);
        return solve(trees);
    }

    TreeNode* solve(queue<string>& trees) {
        if (trees.empty()) {
            return nullptr;
        }

        if (trees.front() == "null") {
            trees.pop();
            return nullptr;
        }

        TreeNode* root = new TreeNode(stoi(trees.front()));
        trees.pop();
        root->left = solve(trees);
        root->right = solve(trees);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));