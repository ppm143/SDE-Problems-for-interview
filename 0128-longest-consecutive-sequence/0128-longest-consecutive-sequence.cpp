class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        for (int& num : nums)
            st.insert(num);
        int ans = 0;
        for (auto x : st) {
            if (st.contains(x - 1))
                continue;
            int nm = x, cnt = 0;
            while (st.contains(nm)) {
                cnt++;
                nm++;
            }
            ans = max(ans, cnt);
        }
        return ans;
    }
};