class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        unordered_map<string, int> memo;
        return dfs(0, true, prices, memo);
    }

    int dfs(int idx, bool buying, vector<int>& prices,
            unordered_map<string, int>& memo) {
        if (idx >= prices.size())
            return 0;

        string key = to_string(idx) + "_" + to_string(buying);
        if (memo.find(key) != memo.end())
            return memo[key];

        if (buying) {
            int buy = dfs(idx + 1, false, prices, memo) - prices[idx];
            int cooldown = dfs(idx + 1, buying, prices, memo);

            return memo[key] = max(buy, cooldown);
        } else {
            int sell = dfs(idx + 2, true, prices, memo) + prices[idx];
            int cooldown = dfs(idx + 1, buying, prices, memo);

            return memo[key] = max(sell, cooldown);
        }
    }
};