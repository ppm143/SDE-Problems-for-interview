class Solution {
    vector<int> prevSmallers(vector<int>& H) {
        int n = H.size();
        stack<int> stk;
        vector<int> ans(n, -1);
        stk.push(0);
        for (int i = 1; i < n; i++) {
            while (!stk.empty() and H[stk.top()] >= H[i])
                stk.pop();
            if (!stk.empty())
                ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }
    vector<int> nextSmallers(vector<int>& H) {
        int n = H.size();
        stack<int> stk;
        vector<int> ans(n, n);
        stk.push(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            while (!stk.empty() and H[stk.top()] >= H[i])
                stk.pop();
            if (!stk.empty())
                ans[i] = stk.top();
            stk.push(i);
        }
        return ans;
    }

public:
    int largestRectangleArea(vector<int>& heights) {
        vector<int> PS = prevSmallers(heights);
        vector<int> NS = nextSmallers(heights);
        int largestRectangleArea = 0;
        for (int i = 0; i < heights.size(); i++)
            largestRectangleArea =
                max(largestRectangleArea, (NS[i] - PS[i] - 1) * heights[i]);
        return largestRectangleArea;
    }
};