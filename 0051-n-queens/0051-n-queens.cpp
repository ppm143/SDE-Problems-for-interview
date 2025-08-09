class Solution {
    bool isSafe(int r, int c, vector<string>& board) {
        int n = board.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                bool isSameRowOrCol = (i == r or j == c);
                bool isSameDiag = (j - i == c - r or i + j == c + r);
                if (isSameRowOrCol or isSameDiag)
                    return false;
            }
        }
        return true;
    }
    void solve(int r, vector<string>& board, vector<vector<string>>& ans) {
        if (r == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < board.size(); c++) {
            if (isSafe(r, c, board)) {
                board[r][c] = 'Q';
                solve(r + 1, board, ans);
                board[r][c] = '.';
            }
        }
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, board, ans);
        return ans;
    }
};