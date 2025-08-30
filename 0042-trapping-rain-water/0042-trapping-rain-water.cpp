class Solution {
public:
    int trap(vector<int>& height) {
        int s = 0, e = height.size() - 1;
        int ans = 0, leftMax = height[s], rightMax = height[e];
        while (s < e) {
            if (leftMax < rightMax) {
                s++;
                leftMax = max(leftMax, height[s]);
                ans += leftMax - height[s];
            } else {
                e--;
                rightMax = max(rightMax, height[e]);
                ans += rightMax - height[e];
            }
        }
        return ans;
    }
};