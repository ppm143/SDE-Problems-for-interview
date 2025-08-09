class Solution {
    int solve(vector<int>& memo, vector<int>& nums, int s, int e) {
        memo[s] = nums[s];
        memo[s + 1] = max(nums[s], nums[s + 1]);
        for (int i = s + 2; i <= e; i++) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        return memo[e];
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, 0);
        if(n == 1) return nums[0];
        return solve(memo, nums, 0, n - 1);
    }
};