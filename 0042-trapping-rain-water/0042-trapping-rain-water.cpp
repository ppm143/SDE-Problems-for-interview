class Solution {
public:
    int trap(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int ans = 0, leftMax = 0, rightMax = 0;
        while (s < e) {
            if (height[s] < height[e]) {
                leftMax = max(leftMax, height[s]);
                ans += leftMax - height[s];
                s++;
            } else {
                rightMax = max(rightMax, height[e]);
                ans += rightMax - height[e];
                e--;
            }
        }
        return ans;
    }
};