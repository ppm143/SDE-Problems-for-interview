class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int r = 0; r < numRows; r++) {
            for (int c = 0; c <= r; c++) {
                if (c == 0 or c == r)
                    ans[r].push_back(1);
                else
                    ans[r].push_back(ans[r - 1][c] + ans[r - 1][c - 1]);
            }
        }
        return ans;
    }
};