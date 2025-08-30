class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        map<int, vector<int>> diagonals;
        int n = mat.size(), m = mat[0].size();

        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                diagonals[r + c].push_back(mat[r][c]);
            }
        }

        vector<int> ans;
        int level = 0;
        for (auto [idx, diagonal] : diagonals) {
            if (level % 2 == 0)
                ans.insert(ans.end(), diagonal.rbegin(), diagonal.rend());
            else
                ans.insert(ans.end(), diagonal.begin(), diagonal.end());
            level++;
        }
        return ans;
    }
};