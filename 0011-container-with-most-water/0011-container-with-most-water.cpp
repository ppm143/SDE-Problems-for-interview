class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int maxArea = 0;
        while (s < e) {
            int currArea = (e - s) * min(height[s], height[e]);
            maxArea = max(maxArea, currArea);
            if (height[s] < height[e])
                s++;
            else
                e--;
        }
        return maxArea;
    }
};