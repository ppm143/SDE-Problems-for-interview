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
        if (!root)
            return 0;
        auto [maxH, maxDia] = findDiameter(root);
        return maxDia;
    }

    pair<int, int> findDiameter(TreeNode* root) {
        if (!root)
            return {0, 0};

        auto [lH, lDia] = findDiameter(root->left);
        auto [rH, rDia] = findDiameter(root->right);

        return {max(lH, rH) + 1, max({lDia, rDia, lH + rH})};
    }
};