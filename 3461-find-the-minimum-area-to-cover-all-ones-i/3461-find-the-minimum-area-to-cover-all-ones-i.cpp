class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int minR = n, minC = m, maxR = 0, maxC = 0;
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (grid[r][c]) {
                    minR = min(minR, r);
                    maxR = max(maxR, r);
                    minC = min(minC, c);
                    maxC = max(maxC, c);
                }
            }
        }

        return (maxR - minR + 1) * (maxC - minC + 1);
    }
};