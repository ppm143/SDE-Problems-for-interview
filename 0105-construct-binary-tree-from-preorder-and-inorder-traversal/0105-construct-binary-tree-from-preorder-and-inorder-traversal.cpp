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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int ie = inorder.size() - 1;
        unordered_map<int, int> inorderMap;
        for (int i = 0; i <= ie; i++)
            inorderMap[inorder[i]] = i;
        return solve(preorder, inorderMap, 0, ie, 0);
    }

    TreeNode* solve(vector<int>& preorder, unordered_map<int, int>& inorderMap,
                    int is, int ie, int ps) {
        if (is > ie or ps > preorder.size())
            return nullptr;
        int node = preorder[ps];
        TreeNode* root = new TreeNode(node);
        int idx = inorderMap[node];
        int left = idx - is;
        root->left = solve(preorder, inorderMap, is, idx - 1, ps + 1);
        root->right = solve(preorder, inorderMap, idx + 1, ie, ps + left + 1);
        return root;
    }
};