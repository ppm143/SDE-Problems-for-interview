/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1)
            return new TreeNode(val, root, nullptr);
        solve(root, val, depth - 1);
        return root;
    }

    void solve(TreeNode* node, int val, int depth) {
        if (node == nullptr)
            return;

        if (depth == 1) {
            node->left = new TreeNode(val, node->left, nullptr);
            node->right = new TreeNode(val, nullptr, node->right);
            return;
        }

        solve(node->left, val, depth - 1);
        solve(node->right, val, depth - 1);
    }
};