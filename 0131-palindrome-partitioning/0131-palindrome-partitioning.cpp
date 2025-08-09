class Solution {
    void solve(int idx, string& s, vector<vector<string>>& ans,
               vector<string>& ds) {
        if (idx == s.size()) {
            ans.push_back(ds);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPalindrome(idx, i, s)) {
                ds.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, ans, ds);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(int l, int r, string& s) {
        while (l <= r) {
            if (s[l] == s[r]) {
                l++;
                r--;
            } else
                return false;
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> ds;
        solve(0, s, ans, ds);
        return ans;
    }
};