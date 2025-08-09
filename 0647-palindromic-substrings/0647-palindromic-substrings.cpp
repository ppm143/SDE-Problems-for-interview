class Solution {
    int countPalindrom(int L, int R, string& s) {
        int length = 0;
        while (L >= 0 and R < s.size() and s[L] == s[R]) {
            L--;
            R++;
            length++;
        }
        return length;
    }

public:
    int countSubstrings(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans += countPalindrom(i, i, s);
            ans += countPalindrom(i, i + 1, s);
        }
        return ans;
    }
};