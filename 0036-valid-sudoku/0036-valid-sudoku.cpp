class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        unordered_map<int, unordered_set<int>> row, col, sqr;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int sqrno = (i / 3) * 3 + j / 3;
                int nm = board[i][j];
                if (nm == '.')
                    continue;
                if (row[i].contains(nm) or col[j].contains(nm) or
                    sqr[sqrno].contains(nm)) {
                    return false;
                }
                row[i].insert(nm);
                col[j].insert(nm);
                sqr[sqrno].insert(nm);
            }
        }
        return true;
    }
};