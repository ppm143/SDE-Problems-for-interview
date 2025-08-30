class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int M = mat.size();
        if (!M)
            return 0;

        int N = mat[0].size();
        if (!N)
            return 0;

        int count = 0;
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                count += countArea(i, j, mat);
            }
        }

        return count;
    }

    int countArea(int y, int x, vector<vector<int>>& mat) {
        int count = 0;
        int maxColumn = -1;
        for (int i = y; i > -1; --i) {
            for (int j = x; j > maxColumn; --j) {
                if (mat[i][j])
                    ++count;
                else
                    maxColumn = j;
            }
        }

        return count;
    }
};