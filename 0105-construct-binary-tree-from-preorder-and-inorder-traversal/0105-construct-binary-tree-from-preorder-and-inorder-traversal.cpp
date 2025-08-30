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
    int ps = 0;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = inorder.size() - 1;
        unordered_map<int, int> inorderMap;
        for (int i = 0; i <= n; i++)
            inorderMap[inorder[i]] = i;
        return solve(preorder, inorderMap, 0, n);
    }

    TreeNode* solve(vector<int>& preorder, unordered_map<int, int>& inorderMap,
                    int l, int r) {
        if (l > r)
            return nullptr;
        int node = preorder[ps++];
        TreeNode* root = new TreeNode(node);
        int m = inorderMap[node];
        root->left = solve(preorder, inorderMap, l, m - 1);
        root->right = solve(preorder, inorderMap, m + 1, r);
        return root;
    }
};