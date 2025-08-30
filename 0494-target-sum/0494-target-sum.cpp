class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<string, int> memo;
        return dfs(0, 0, target, nums, memo);
    }

    int dfs(int idx, int sum, int target, vector<int>& nums,
            unordered_map<string, int>& memo) {
        if (idx == nums.size())
            return sum == target;

        string key = to_string(idx) + "_" + to_string(sum);
        if (memo.find(key) != memo.end())
            return memo[key];

        int plus = dfs(idx + 1, sum + nums[idx], target, nums, memo);
        int minus = dfs(idx + 1, sum - nums[idx], target, nums, memo);

        return memo[key] = plus + minus;
    }
};