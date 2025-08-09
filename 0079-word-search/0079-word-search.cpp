class Solution {
    bool solve(int r, int c, int idx, string& word,
               vector<vector<char>>& board) {
        if (idx == word.size())
            return true;

        if (r < 0 or c < 0 or r >= board.size() or c >= board[0].size() or
            board[r][c] != word[idx])
            return false;

        char ch = board[r][c];
        board[r][c] = '#';
        bool isPossible = solve(r, c + 1, idx + 1, word, board) or
                          solve(r + 1, c, idx + 1, word, board) or
                          solve(r - 1, c, idx + 1, word, board) or
                          solve(r, c - 1, idx + 1, word, board);

        board[r][c] = ch;
        return isPossible;
    }

public:
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size();
        int m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (solve(i, j, 0, word, board))
                    return true;
            }
        }
        return false;
    }
};