class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum & 1)
            return false;

        int target = sum / 2;
        vector<vector<int>> memo(n, vector<int>(target + 1, -1));

        return dfs(0, target, nums, memo);
    }

    bool dfs(int idx, int target, vector<int>& nums,
             vector<vector<int>>& memo) {
        if (idx == memo.size())
            return target == 0;

        if (target < 0)
            return false;

        if (memo[idx][target] != -1)
            return memo[idx][target];

        memo[idx][target] = dfs(idx + 1, target, nums, memo) or
                            dfs(idx + 1, target - nums[idx], nums, memo);
        return memo[idx][target];
    }
};