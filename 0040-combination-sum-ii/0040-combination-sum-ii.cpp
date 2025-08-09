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
        solve(idx + 1, sum - nums[idx], nums, ds, ans);
        ds.pop_back();

        while (idx + 1 < nums.size() and nums[idx] == nums[idx + 1])
            idx++;
        solve(idx + 1, sum, nums, ds, ans);
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(candidates.begin(), candidates.end());
        solve(0, target, candidates, ds, ans);
        return ans;
    }
};