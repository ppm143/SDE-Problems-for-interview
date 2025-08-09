class Solution {
    int climbStairsTD(int n, unordered_map<int, int>& memo) {
        // Base cases
        if (n == 0 or n == 1)
            return 1;

        if (memo.find(n) != memo.end())
            return memo[n];
        return memo[n] =
                   climbStairsTD(n - 1, memo) + climbStairsTD(n - 2, memo);
    }

    int climbStairsBU(int n) {
        vector<int> memo(n + 1, 0);
        // Base cases
        memo[0] = 1;
        memo[1] = 1;

        for (int i = 2; i <= n; i++)
            memo[i] = memo[i - 1] + memo[i - 2];
        return memo[n];
    }

    int climbStairsBUOptimizedSpace(int n) {
        if (n == 0 or n == 1)
            return 1;

        int prev = 1, curr = 1;
        for (int i = 2; i <= n; i++) {
            int temp = curr;
            curr = prev + curr;
            prev = temp;
        }
        return curr;
    }

public:
    int climbStairs(int n) { return climbStairsBUOptimizedSpace(n); }
};