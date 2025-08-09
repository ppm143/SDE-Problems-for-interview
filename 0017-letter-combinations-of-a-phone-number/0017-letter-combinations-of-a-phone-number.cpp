class Solution {
    void solve(int idx, string& digits, string& current,
               vector<string>& mapping, vector<string>& ans) {
        if (idx == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letter = mapping[digits[idx] - '0'];
        for (char& ch : letter) {
            current.push_back(ch);
            solve(idx + 1, digits, current, mapping, ans);
            current.pop_back();
        }
    }

public:
    vector<string> letterCombinations(string digits) {
        vector<string> mapping = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };
        string current;
        vector<string> ans;
        if (digits.empty())
            return ans;
        solve(0, digits, current, mapping, ans);
        return ans;
    }
};