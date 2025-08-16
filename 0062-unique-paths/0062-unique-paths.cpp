class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> row(n, 1);

        for (int i = 0; i < m - 1; i++) {
            vector<int> newRow(n, 1);
            for (int j = n - 2; j >= 0; j--)
                newRow[j] = row[j] + newRow[j + 1];
            row = newRow;
        }

        return row[0];
    }

    int uniquePathsDP(int m, int n) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        dp[m - 1][n - 1] = 1;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--)
                dp[i][j] += dp[i + 1][j] + dp[i][j + 1];
        }

        return dp[0][0];
    }
};