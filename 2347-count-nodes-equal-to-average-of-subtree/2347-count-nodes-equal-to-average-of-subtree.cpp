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
    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
    pair<int, int> solve(TreeNode* root, int& ans) {
        if (root == nullptr) {
            return {0, 0};
        }
        auto [lSum, lCnt] = solve(root->left, ans);
        auto [rSum, rCnt] = solve(root->right, ans);
        int sum = root->val + lSum + rSum;
        int cnt = 1 + lCnt + rCnt;
        if (sum / cnt == root->val)
            ans++;
        return {sum, cnt};
    }
};