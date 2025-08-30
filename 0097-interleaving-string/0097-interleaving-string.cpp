class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int nn = s3.size();
        int n = s1.size();
        int m = s2.size();
        if (n + m != nn)
            return false;

        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));
        return dfs(0, 0, 0, s1, s2, s3, memo);
    }

    bool dfs(int i, int j, int idx, string& s1, string& s2, string& s3,
             vector<vector<int>>& memo) {
        if (idx == s3.size())
            return i == s1.size() and j == s2.size();

        if (memo[i][j] != -1)
            return memo[i][j];

        if (i < s1.size() and s1[i] == s3[idx]) {
            if (dfs(i + 1, j, idx + 1, s1, s2, s3, memo))
                return memo[i][j] = true;
        }
        if (j < s2.size() and s2[j] == s3[idx]) {
            if (dfs(i, j + 1, idx + 1, s1, s2, s3, memo))
                return memo[i][j] = true;
        }
        return memo[i][j] = false;
    }
};