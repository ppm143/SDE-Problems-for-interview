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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> Q;
        Q.push(root);
        int level_no = 0;
        vector<int> level;
        while (!Q.empty()) {
            int q_size = Q.size();
            for (int i = 0; i < q_size; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                level.emplace_back(node->val);
                if (node->left)
                    Q.push(node->left);
                if (node->right)
                    Q.push(node->right);
            }
            if (level_no % 2)
                reverse(level.begin(), level.end());
            level_no++;
            ans.emplace_back(level);
            level.clear();
        }
        return ans;
    }
};