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
    int goodNodes(TreeNode* root) {
        int mx = INT_MIN;
        return solve(root, mx);
    }

    int solve(TreeNode* root, int mx) {
        if (root == nullptr)
            return 0;
        int count = root->val >= mx ? 1 : 0;
        mx = max(mx, root->val);
        count += solve(root->left, mx);
        count += solve(root->right, mx);
        return count;
    }
};