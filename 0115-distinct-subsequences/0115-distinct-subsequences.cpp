class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n)
            return 0;
        vector<vector<int>> memo(n, vector<int>(m, -1));
        return dfs(0, 0, s, t, memo);
    }

    int dfs(int i, int j, string& s, string& t, vector<vector<int>>& memo) {
        if (j == t.size())
            return 1;
        if (i == s.size())
            return 0;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] == t[j])
            memo[i][j] =
                dfs(i + 1, j + 1, s, t, memo) + dfs(i + 1, j, s, t, memo);
        else
            memo[i][j] = dfs(i + 1, j, s, t, memo);

        return memo[i][j];
    }
};