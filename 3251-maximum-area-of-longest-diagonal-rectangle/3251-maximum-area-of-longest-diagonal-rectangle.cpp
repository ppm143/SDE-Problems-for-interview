class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        long long diaLen = 0, area = 0, maxArea = 0, maxDia = 0, d1, d2;
        for (auto dimension : dimensions) {
            d1 = dimension[0];
            d2 = dimension[1];
            diaLen = d1 * d1 + d2 * d2;
            area = d1 * d2;
            if (diaLen > maxDia or (diaLen == maxDia and area > maxArea)) {
                maxDia = diaLen;
                maxArea = area;
            }
        }
        return maxArea;
    }
};