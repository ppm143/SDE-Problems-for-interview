class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<int> st;
        int n = temp.size();
        vector<int> ans(n, 0);
        st.push(n - 1);
        ans[n - 1] = 0;
        for (int i = n - 2; i >= 0; i--) {
            while (!st.empty() and temp[st.top()] <= temp[i])
                st.pop();
            if (!st.empty())
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};