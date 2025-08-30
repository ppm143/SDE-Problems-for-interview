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
        if (!root or !p or !q)
            return nullptr;

        int maxVal = max(p->val, q->val);
        int minVal = min(p->val, q->val);

        if (maxVal < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (minVal > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else
            return root;
    }
};