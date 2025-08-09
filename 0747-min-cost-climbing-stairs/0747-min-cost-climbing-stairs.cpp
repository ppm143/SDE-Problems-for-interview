class Solution {
    unordered_map<int, int> memo;
    int go(vector<int>& cost, int idx) {
        if (idx >= cost.size()) {
            return 0;
        }
        if (memo.find(idx) != memo.end()) {
            return memo[idx];
        }
        memo[idx] = cost[idx] + min(go(cost, idx + 1), go(cost, idx + 2));
        return memo[idx];
    }

    int minCostClimbingStairsBU(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            memo[i] = min(memo[i - 1] + cost[i - 1], memo[i - 2] + cost[i - 2]);
        }
        return memo[n];
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(go(cost, 0), go(cost, 1));
    }
};