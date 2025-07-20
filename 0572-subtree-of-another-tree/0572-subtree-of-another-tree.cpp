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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root == nullptr)
            return false;
        if (isSame(root, subRoot))
            return true;
        return isSubtree(root->left, subRoot) or
               isSubtree(root->right, subRoot);
    }

    bool isSame(TreeNode* p, TreeNode* q) {
        if (p == nullptr and q == nullptr)
            return true;
        if (p == nullptr or q == nullptr or p->val != q->val)
            return false;

        return isSame(p->left, q->left) and isSame(p->right, q->right);
    }
};