class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int i = 1; i <= amount; i++) {
            for (int& coin : coins) {
                if (i >= coin) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        return dp[amount] != amount + 1 ? dp[amount] : -1;
    }

    int coinChangeBFS(vector<int>& coins, int amount) {
        if (amount == 0)
            return 0;
        queue<int> Q;
        Q.push(0);
        vector<int> seen(amount + 1, false);
        seen[0] = true;
        int res = 0;
        while (!Q.empty()) {
            int qSize = Q.size();
            res++;
            for (int i = 0; i < qSize; i++) {
                int currAmount = Q.front();
                Q.pop();
                for (int& coin : coins) {
                    int nextAmount = currAmount + coin;
                    if (nextAmount == amount)
                        return res;
                    if (nextAmount > amount or seen[nextAmount])
                        continue;
                    Q.push(nextAmount);
                    seen[nextAmount] = true;
                }
            }
        }
        return -1;
    }
};