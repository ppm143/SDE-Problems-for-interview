class Solution {
    string expandAroundCenter(int L, int R, string& s) {
        while (L >= 0 and R < s.size() and s[L] == s[R])
            L--, R++;

        return s.substr(L + 1, R - L - 1);
    }
    string findMax(string& odd, string& even, string& s) {
        if (odd.size() > s.size()) {
            s = odd;
        }
        if (even.size() > s.size()) {
            s = even;
        }
        return s;
    }

public:
    string longestPalindrome(string s) {
        string longest, oddStr, evenStr;
        for (int i = 0; i < s.size(); i++) {
            oddStr = expandAroundCenter(i, i, s);
            evenStr = expandAroundCenter(i, i + 1, s);
            longest = findMax(oddStr, evenStr, longest);
        }
        return longest;
    }
};