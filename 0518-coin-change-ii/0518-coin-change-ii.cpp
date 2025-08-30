class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        sort(coins.begin(), coins.end());
        vector<vector<int>> memo(n + 1, vector<int>(amount + 1, -1));
        return dfs(0, amount, coins, memo);
    }

    int dfs(int idx, int amount, vector<int>& coins,
            vector<vector<int>>& memo) {
        if (idx >= coins.size())
            return 0;

        if (amount == 0)
            return 1;

        if (memo[idx][amount] != -1)
            return memo[idx][amount];

        int ans = 0;
        if (coins[idx] <= amount) {
            int skip = dfs(idx + 1, amount, coins, memo);
            int use = dfs(idx, amount - coins[idx], coins, memo);
            ans = skip + use;
        }

        return memo[idx][amount] = ans;
    }
};