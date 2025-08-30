class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size() - 1;
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0)
                break;
            // to avoid duplicate
            if (i > 0 and nums[i] == nums[i - 1])
                continue;
            solveTwoSum(i, n, nums, ans);
        }
        return ans;
    }

    void solveTwoSum(int idx, int e, vector<int>& nums,
                     vector<vector<int>>& ans) {
        int s = idx + 1;
        while (s < e) {
            int sum = nums[s] + nums[e];
            if (sum == -nums[idx]) {
                ans.push_back({nums[idx], nums[s], nums[e]});
                s++;
                e--;
                // to avoid duplicate
                while (s < e and nums[s] == nums[s - 1])
                    s++;
            } else if (sum > -nums[idx])
                e--;
            else
                s++;
        }
    }
};