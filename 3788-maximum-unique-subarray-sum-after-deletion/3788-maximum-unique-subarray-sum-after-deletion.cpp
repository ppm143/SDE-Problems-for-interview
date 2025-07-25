class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int> st;
        int sum = 0, mx = INT_MIN;
        for (int& num : nums) {
            if (num <= 0 or st.contains(num)) {
                mx = max(mx, num);
                continue;
            }
            sum += num;
            st.insert(num);
        }
        return !st.empty() ? sum : mx;
    }
};