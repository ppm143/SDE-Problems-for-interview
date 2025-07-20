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
    bool isBalanced(TreeNode* root) { return dfs(root).first; }
    pair<bool, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {true, 0};

        auto [lB, lH] = dfs(root->left);
        auto [rB, rH] = dfs(root->right);

        bool isBalanced = lB and rB and abs(lH - rH) <= 1;
        int height = max(lH, rH) + 1;

        return {isBalanced, height};
    }
};