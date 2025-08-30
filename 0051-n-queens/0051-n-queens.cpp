class Solution {
    bool isSafe(int r, int c) {
        return !col.contains(c) and !posDiag.contains(r + c) and
               !negDiag.contains(r - c);
    }
    void solve(int r, vector<string>& board, vector<vector<string>>& ans) {
        if (r == board.size()) {
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < board.size(); c++) {
            if (!isSafe(r, c))
                continue;

            board[r][c] = 'Q';
            col.insert(c);
            posDiag.insert(r + c);
            negDiag.insert(r - c);

            solve(r + 1, board, ans);

            col.erase(c);
            posDiag.erase(r + c);
            negDiag.erase(r - c);
            board[r][c] = '.';
        }
    }

public:
    unordered_set<int> col;
    unordered_set<int> posDiag;
    unordered_set<int> negDiag;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0, board, ans);
        return ans;
    }
};