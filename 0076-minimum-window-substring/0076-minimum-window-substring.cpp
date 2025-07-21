class Solution {
    bool isValidWindow(unordered_map<char, int>& mp1,
                       unordered_map<char, int>& mp2) {
        for (auto& [ch, freq] : mp1) {
            if (freq > mp2[ch])
                return false;
        }
        return true;
    }

public:
    string minWindow(string s, string t) {
        int ss = s.size(), ts = t.size(), L = 0;
        string ans = "";
        if (ts > ss)
            return ans;
        unordered_map<char, int> mpt, mps;
        int window = INT_MAX, start = 0;
        for (int i = 0; i < ts; i++)
            mpt[t[i]]++;
        for (int R = 0; R < ss; R++) {
            mps[s[R]]++;
            while (isValidWindow(mpt, mps)) {
                if (window > (R - L + 1)) {
                    window = R - L + 1;
                    start = L;
                }
                mps[s[L]]--, L++;
            }
        }
        if (window == INT_MAX)
            return ans;
        return s.substr(start, window);
    }
};