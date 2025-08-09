class Solution {
    void solve(int idx, vector<int>& ds, vector<int>& nums,
               vector<vector<int>>& ans) {
        if (idx == nums.size()) {
            ans.push_back(ds);
            return;
        }
        //include element
        ds.push_back(nums[idx]);
        solve(idx + 1, ds, nums, ans);
        ds.pop_back();

        //skip same element as number sorted
        while (idx + 1 < nums.size() and nums[idx] == nums[idx + 1])
            idx++;
        //skip element    
        solve(idx + 1, ds, nums, ans);
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        sort(nums.begin(), nums.end());
        solve(0, ds, nums, ans);
        return ans;
    }
};