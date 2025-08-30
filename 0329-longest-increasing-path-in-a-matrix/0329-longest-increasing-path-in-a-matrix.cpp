class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> memo(n, vector<int>(m, -1));
        int LIP = 1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                LIP = max(LIP, dfs(i, j, INT_MIN, matrix, memo));
            }
        }
        return LIP;
    }

    int dfs(int x, int y, int prevVal, vector<vector<int>>& matrix,
            vector<vector<int>>& memo) {
        if (x >= matrix.size() or y >= matrix[0].size() or x < 0 or y < 0 or
            matrix[x][y] <= prevVal)
            return 0;

        if (memo[x][y] != -1)
            return memo[x][y];

        vector<int> dir = {-1, 0, 1, 0, -1};

        int ans = 1;
        for (int d = 0; d < 4; d++) {
            int newX = x + dir[d];
            int newY = y + dir[d + 1];
            ans = max(ans, 1 + dfs(newX, newY, matrix[x][y], matrix, memo));
        }

        return memo[x][y] = ans;
    }
};