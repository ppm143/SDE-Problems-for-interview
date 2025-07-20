class Solution {
public:
    bool isValid(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    void bfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int a,
             int b) {
        int n = visited.size();
        int m = visited[0].size();
        queue<pair<int, int>> Q;
        Q.push({a, b});
        visited[a][b] = true;
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (isValid(newX, newY, n, m) and !visited[newX][newY] and
                    grid[newX][newY] == '1') {
                    visited[newX][newY] = true;
                    Q.push({newX, newY});
                }
            }
        }
    }

    void dfs(vector<vector<bool>>& visited, vector<vector<char>>& grid, int x,
             int y) {
        int n = visited.size();
        int m = visited[0].size();
        visited[x][y] = true;
        vector<int> dir = {-1, 0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int newX = x + dir[i];
            int newY = y + dir[i + 1];
            if (isValid(newX, newY, n, m) and !visited[newX][newY] and
                grid[newX][newY] == '1') {
                visited[newX][newY] = true;
                dfs(visited, grid, newX, newY);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int noOfIslands = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j] and grid[i][j] == '1') {
                    noOfIslands++;
                    dfs(visited, grid, i, j);
                }
            }
        }
        return noOfIslands;
    }
};