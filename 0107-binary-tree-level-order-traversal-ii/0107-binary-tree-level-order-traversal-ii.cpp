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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int total_depth = findDepth(root);
        vector<vector<int>> ans;
        for (int i = 0; i < total_depth; i++)
            ans.push_back({});
        int depth = 0;
        solve(root, depth, ans);
        return ans;
    }

    void solve(TreeNode* root, int depth, vector<vector<int>>& ans) {
        if (root == nullptr)
            return;
        ans[ans.size() - depth - 1].push_back(root->val);
        solve(root->left, depth + 1, ans);
        solve(root->right, depth + 1, ans);
    }
    int findDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(findDepth(root->left), findDepth(root->right)) + 1;
    }
};