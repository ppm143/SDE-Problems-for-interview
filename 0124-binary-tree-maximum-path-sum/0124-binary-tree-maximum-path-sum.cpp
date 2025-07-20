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
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        solve(root, ans);
        return ans;
    }
    int solve(TreeNode* root, int& maxi) {
        if (root == nullptr)
            return 0;

        int lSum = max(0, solve(root->left, maxi));
        int rSum = max(0, solve(root->right, maxi));

        maxi = max(maxi, lSum + rSum + root->val);
        return root->val + max(lSum, rSum);
    }
};