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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int qSize = Q.size();

            for (int i = 0; i < qSize; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                if (node->left != nullptr) {
                    Q.push(node->left);
                    parent[node->left->val] = node;
                }
                if (node->right != nullptr) {
                    Q.push(node->right);
                    parent[node->right->val] = node;
                }
            }
        }

        Q.push(target);
        unordered_map<TreeNode*, int> visited;
        while (k-- and !Q.empty()) {
            int qSize = Q.size();

            for (int i = 0; i < qSize; i++) {
                TreeNode* node = Q.front();
                Q.pop();
                visited[node] = 1;
                if (node->left != nullptr and !visited[node->left])
                    Q.push(node->left);

                if (node->right != nullptr and !visited[node->right])
                    Q.push(node->right);

                if (parent[node->val] and !visited[parent[node->val]])
                    Q.push(parent[node->val]);
            }
        }
        while (!Q.empty()) {
            ans.push_back(Q.front()->val);
            Q.pop();
        }
        return ans;
    }
};