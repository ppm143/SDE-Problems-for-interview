class Solution {
    bool isValid(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited,
            queue<pair<int, int>>& Q, int freshOranges) {
        if (!freshOranges)
            return 0;
        int n = grid.size(), m = grid[0].size();
        int time = 0;
        vector<int> dir = {-1, 0, 1, 0, -1};

        while (!Q.empty() and freshOranges > 0) {
            int qSize = Q.size();
            for (int q = 0; q < qSize; q++) {
                auto [x, y] = Q.front();
                Q.pop();
                for (int i = 0; i < 4; i++) {
                    int newX = x + dir[i];
                    int newY = y + dir[i + 1];
                    if (isValid(newX, newY, n, m) and !visited[newX][newY] and
                        grid[newX][newY] == 1) {
                        visited[newX][newY] = true;
                        Q.push({newX, newY});
                        freshOranges--;
                    }
                }
            }
            time++;
        }
        return freshOranges ? -1 : time;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        queue<pair<int, int>> Q;
        int freshOranges = 0;
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < m; y++) {
                if (grid[x][y] == 2)
                    Q.push({x, y});
                if (grid[x][y] == 1)
                    freshOranges++;
            }
        }
        return bfs(grid, visited, Q, freshOranges);
    }
};