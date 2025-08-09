class Solution {
    void solve(int idx, int sum, vector<int>& nums, vector<int>& ds,
               vector<vector<int>>& ans) {
        if (sum == 0) {
            ans.push_back(ds);
            return;
        }
        if (idx == nums.size() or sum < 0)
            return;

        ds.push_back(nums[idx]);
        solve(idx, sum - nums[idx], nums, ds, ans);
        ds.pop_back();

        solve(idx + 1, sum, nums, ds, ans);
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        int sum = target;
        solve(0, sum, candidates, ds, ans);
        return ans;
    }
};