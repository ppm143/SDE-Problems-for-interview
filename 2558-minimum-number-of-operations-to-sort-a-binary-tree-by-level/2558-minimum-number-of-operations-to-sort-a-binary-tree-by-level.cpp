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
    int minimumOperations(TreeNode* root) {
        int ans = 0;
        queue<TreeNode*> Q;
        Q.push(root);
        vector<int> currentLevelValues;
        while (!Q.empty()) {
            int qSize = Q.size();
            for (int i = 0; i < qSize; i++) {
                TreeNode* currNode = Q.front();
                Q.pop();
                currentLevelValues.emplace_back(currNode->val);
                if (currNode->left)
                    Q.push(currNode->left);
                if (currNode->right)
                    Q.push(currNode->right);
            }
            ans += minimumSwap(currentLevelValues);
            currentLevelValues.clear();
        }

        return ans;
    }

    int minimumSwap(vector<int> nums) {
        int n = nums.size();
        vector<bool> visited(n, false);
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
            mp[nums[i]] = i;
        sort(nums.begin(), nums.end());

        int swaps = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] or mp[nums[i]] == i)
                continue;
            int j = i, cycles = 0;
            while (!visited[j]) {
                visited[j] = true;
                j = mp[nums[j]];
                cycles++;
            }
            if (cycles > 0)
                swaps += (cycles - 1);
        }
        return swaps;
    }
};