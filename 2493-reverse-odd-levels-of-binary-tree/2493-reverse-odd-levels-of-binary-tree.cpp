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
    TreeNode* reverseOddLevels(TreeNode* root) {
        bool isOddLevel = true;
        solve(root->left, root->right, isOddLevel);
        return root;
    }

    void solve(TreeNode* leftChild, TreeNode* rightChild, bool isOddLevel) {
        if (leftChild == nullptr or rightChild == nullptr)
            return;

        if (isOddLevel)
            swap(leftChild->val, rightChild->val);

        solve(leftChild->left, rightChild->right, !isOddLevel);
        solve(leftChild->right, rightChild->left, !isOddLevel);
    }
};

/*
TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr)
            return root;

        queue<TreeNode*> Q;
        Q.push(root);
        vector<TreeNode*> currentLevelNodes;
        int currentLevel = 1;
        while (!Q.empty()) {
            int qSize = Q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* currentNode = Q.front();
                Q.pop();
                currentLevelNodes.emplace_back(currentNode);
                if (currentNode->left)
                    Q.push(currentNode->left);
                if (currentNode->right)
                    Q.push(currentNode->right);
            }
            if (currentLevel % 2 == 0) {
                int left = 0;
                int right = currentLevelNodes.size() - 1;
                while (left < right) {
                    swap(currentLevelNodes[left]->val,
                         currentLevelNodes[right]->val);
                    left++;
                    right--;
                }
            }
            currentLevel++;
            currentLevelNodes.clear();
        }
        return root;
    }
*/