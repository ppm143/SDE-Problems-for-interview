class Solution {
    bool isValid(int x, int y, int n, int m) {
        return x >= 0 and x < n and y >= 0 and y < m;
    }
    void bfs(vector<vector<char>>& B, queue<pair<int, int>> Q) {
        int n = B.size();
        int m = B[0].size();
        vector<int> dir = {-1, 0, 1, 0, -1};
        while (!Q.empty()) {
            auto [x, y] = Q.front();
            Q.pop();
            for (int i = 0; i < 4; i++) {
                int newX = x + dir[i];
                int newY = y + dir[i + 1];
                if (isValid(newX, newY, n, m) and B[newX][newY] == 'O') {
                    B[newX][newY] = 'T';
                    Q.push({newX, newY});
                }
            }
        }
    }

public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int, int>> Q;
        for (int x = 0; x < n; x++) {
            if (board[x][0] == 'O') {
                Q.push({x, 0});
                board[x][0] = 'T';
            }
            if (board[x][m - 1] == 'O') {
                Q.push({x, m - 1});
                board[x][m - 1] = 'T';
            }
        }
        for (int y = 0; y < m; y++) {
            if (board[0][y] == 'O') {
                Q.push({0, y});
                board[0][y] = 'T';
            }
            if (board[n - 1][y] == 'O') {
                Q.push({n - 1, y});
                board[n - 1][y] = 'T';
            }
        }
        bfs(board, Q);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};