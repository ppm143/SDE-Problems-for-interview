class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        solve(0, 0, n, ans, "");
        return ans;
    }
    void solve(int open, int close, int n, vector<string>& ans, string s) {
        if (close > open or open > n)
            return;

        if (s.size() == 2 * n) {
            ans.push_back(s);
            return;
        }
        solve(open + 1, close, n, ans, s + "(");
        solve(open, close + 1, n, ans, s + ")");
    }
};