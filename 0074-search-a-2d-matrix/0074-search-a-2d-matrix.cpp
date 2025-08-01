class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int low = 0, high = n * m - 1, mid, num;
        while (low <= high) {
            mid = low + (high - low) / 2;
            num = matrix[mid / m][mid % m];
            if (target == num)
                return true;
            if (target < num)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return false;
    }
};