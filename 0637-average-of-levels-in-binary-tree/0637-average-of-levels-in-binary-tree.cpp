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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<vector<int>> levels;
        int depth = 0;
        solve(root, depth, levels);
        vector<double> ans;
        double avg = 0, sum = 0;
        for (vector<int>& level : levels) {
            sum = accumulate(level.begin(), level.end(), 0L);
            avg = sum / level.size();
            ans.emplace_back(avg);
        }
        return ans;
    }

    void solve(TreeNode* node, int depth, vector<vector<int>>& ans) {
        if (node == nullptr)
            return;

        if (depth == ans.size())
            ans.emplace_back();

        ans[depth].emplace_back(node->val);
        solve(node->left, depth + 1, ans);
        solve(node->right, depth + 1, ans);
    }
};