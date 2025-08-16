class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> LCS(n + 1, vector<int>(m + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                if (text1[i] == text2[j])
                    LCS[i][j] = 1 + LCS[i + 1][j + 1];
                else
                    LCS[i][j] = max(LCS[i + 1][j], LCS[i][j + 1]);
            }
        }
        return LCS[0][0];
    }
};