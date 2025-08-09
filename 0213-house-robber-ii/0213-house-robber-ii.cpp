class Solution {
    int solve(vector<int>& memo, vector<int>& nums, int s, int e) {
        memo[s] = nums[s];
        memo[s + 1] = max(nums[s], nums[s + 1]);
        for (int i = s + 2; i <= e; i++) {
            memo[i] = max(memo[i - 1], memo[i - 2] + nums[i]);
        }
        return memo[e];
    }

    int solve(vector<int>& nums, int s, int e) {
        int prev = nums[s];
        int curr = max(nums[s], nums[s + 1]);
        int ans = curr;
        for (int i = s + 2; i <= e; i++) {
            ans = max(curr, prev + nums[i]);
            prev = curr;
            curr = ans;
        }
        return ans;
    }

public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> memo(n, 0);
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        return max(solve(nums, 0, n - 2), solve(nums, 1, n - 1));
    }
};