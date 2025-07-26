class Solution {
    bool isValid(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int xx,
            int yy) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> Q;
        vector<int> dir = {-1, 0, 1, 0, -1};
        int count = 0;
        Q.push({xx, yy});
        visited[xx][yy] = true;
        count++;
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (isValid(newX, newY, n, m) and !visited[newX][newY] and
                    grid[newX][newY]) {
                    count++;
                    visited[newX][newY] = true;
                    Q.push({newX, newY});
                }
            }
        }
        return count;
    }

public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxAreaOfIsland = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] and !visited[x][y]) {
                    int currAreaOfIsland = bfs(grid, visited, x, y);
                    maxAreaOfIsland = max(maxAreaOfIsland, currAreaOfIsland);
                };
            }
        }
        return maxAreaOfIsland;
    }
};