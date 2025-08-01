class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int left = 0, right = matrix[0].size() - 1, top = 0,
            bottom = matrix.size() - 1;
        int nm = matrix[0].size() * matrix.size();

        vector<int> ans;
        while (left <= right and top <= bottom) {
            for (int i = left; i <= right; i++)
                ans.push_back(matrix[top][i]);

            top++;

            for (int i = top; i <= bottom; i++)
                ans.push_back(matrix[i][right]);

            right--;

            if(ans.size() >= nm) return ans;
            
            for (int i = right; i >= left; i--)
                ans.push_back(matrix[bottom][i]);

            bottom--;

            for (int i = bottom; i >= top; i--)
                ans.push_back(matrix[i][left]);

            left++;
        }
        
        return ans;
    }
};