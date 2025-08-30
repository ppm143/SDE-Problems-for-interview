class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return dfs(0, 0, word1, word2, memo);
    }

    int dfs(int i, int j, string& word1, string& word2,
            vector<vector<int>>& memo) {
        if (i == word1.size())
            return word2.size() - j;
        if (j == word2.size())
            return word1.size() - i;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (word1[i] == word2[j])
            return memo[i][j] = dfs(i + 1, j + 1, word1, word2, memo);

        int insert = dfs(i + 1, j, word1, word2, memo);
        int remove = dfs(i, j + 1, word1, word2, memo);
        int replace = dfs(i + 1, j + 1, word1, word2, memo);

        int ans = min({insert, remove, replace});

        return memo[i][j] = 1 + ans;
    }
};