/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr)
            return root;

        if (root->val <= max(p->val, q->val) and
            root->val >= min(p->val, q->val))
            return root;

        if (root->val <= p->val and root->val <= q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        return lowestCommonAncestor(root->left, p, q);
    }
};