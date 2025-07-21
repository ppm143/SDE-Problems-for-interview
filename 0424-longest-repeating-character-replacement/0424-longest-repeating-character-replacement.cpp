class Solution {
    bool isValidWindow(unordered_map<char, int>& mp, int K, char chh) {
        int cnt = 0, mx = 0;
        for (char ch = 'A'; ch <= 'Z'; ch++) {
            cnt += mp[ch];
            mx = max(mx, mp[ch]);
        }
        return (cnt - K - mx) <= 0;
    }

public:
    int characterReplacement(string s, int k) {
        int L = 0, ans = 0;
        unordered_map<char, int> mp;
        for (int R = 0; R < s.size(); R++) {
            mp[s[R]]++;
            while (!isValidWindow(mp, k, s[R]))
                mp[s[L++]]--;
            ans = max(ans, R - L + 1);
        }
        return ans;
    }
};