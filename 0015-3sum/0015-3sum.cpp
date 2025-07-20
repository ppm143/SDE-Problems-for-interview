class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size() - 1;
        for (int i = 0; i < nums.size() - 2; i++) {
            solveTwoSum(i, n, nums, ans);\
            // to avoid duplicate 
            while (i + 1 < n and nums[i] == nums[i + 1])
                i++;
        }
        return ans;
    }

    void solveTwoSum(int idx, int e, vector<int>& nums, vector<vector<int>>& ans) {
        int s = idx + 1;
        while (s < e) {
            int sum = nums[s] + nums[e];
            if (sum == -nums[idx]) {
                ans.push_back({nums[idx], nums[s], nums[e]});
                // to avoid duplicate 
                while (s < e and nums[s] == ans.back()[1])
                    s++;
                while (s < e and nums[e] == ans.back()[2])
                    e--;
            } else if (sum > -nums[idx])
                e--;
            else
                s++;
        }
    }
};