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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int leftDepth = 1;
        TreeNode* leftNode = root->left;
        while (leftNode) {
            leftNode = leftNode->left;
            leftDepth++;
        }
        int rightDepth = 1;
        TreeNode* rightNode = root->right;
        while (rightNode) {
            rightNode = rightNode->right;
            rightDepth++;
        }
        if (leftDepth == rightDepth)
            return pow(2, leftDepth) - 1;
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};