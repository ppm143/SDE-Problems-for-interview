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
    int diameterOfBinaryTree(TreeNode* root) {
        auto [H, dia] = solve(root);
        return max(H, dia) - 1;
    }
    pair<int, int> solve(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        auto [lH, lDia] = solve(root->left);
        auto [rH, rDia] = solve(root->right);

        return {max(lH, rH) + 1, max({lDia, rDia, lH + rH + 1})};
    }
};