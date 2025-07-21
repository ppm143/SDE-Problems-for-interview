class Solution {
    bool isValidaWindow(unordered_set<char>& st, char ch) {
        return st.find(ch) == st.end();
    }

public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> st;
        int L = 0, ans = 0;
        for (int R = 0; R < s.size(); R++) {
            while (!isValidaWindow(st, s[R]))
                st.erase(s[L++]);
            st.insert(s[R]);
            ans = max(ans, R - L + 1);
        }
        return ans;
    }
};