class Solution {
    bool isValid(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    void bfs(vector<vector<int>>& H, vector<vector<bool>>& visited,
             queue<pair<int, int>> Q) {
        int n = H.size();
        int m = H[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (isValid(newX, newY, n, m) and !visited[newX][newY] and
                    H[x][y] <= H[newX][newY]) {
                    Q.push({newX, newY});
                    visited[newX][newY] = true;
                }
            }
        }
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visitedP(n, vector<bool>(m, false));
        vector<vector<bool>> visitedA(n, vector<bool>(m, false));

        queue<pair<int, int>> PQ, AQ;
        for (int x = 0; x < m; x++) {
            PQ.push({0, x});
            AQ.push({n - 1, x});
            visitedP[0][x] = true;
            visitedA[n - 1][x] = true;
        }
        for (int y = 0; y < n; y++) {
            PQ.push({y, 0});
            AQ.push({y, m - 1});
            visitedP[y][0] = true;
            visitedA[y][m - 1] = true;
        }

        bfs(heights, visitedP, PQ);
        bfs(heights, visitedA, AQ);

        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (visitedP[i][j] and visitedA[i][j])
                    ans.push_back({i, j});
            }
        }
        return ans;
    }
};