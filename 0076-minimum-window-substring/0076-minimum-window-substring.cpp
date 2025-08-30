class Solution {
    bool isValidWindow(unordered_map<char, int>& mpT,
                       unordered_map<char, int>& mpS) {
        for (auto& [ch, freq] : mpT) {
            if (freq > mpS[ch])
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
        unordered_map<char, int> mpT, mpS;
        int window = INT_MAX, start = 0;
        for (int i = 0; i < ts; i++)
            mpT[t[i]]++;
        for (int R = 0; R < ss; R++) {
            mpS[s[R]]++;
            while (isValidWindow(mpT, mpS)) {
                int currentWindow = R - L + 1;
                if (window > currentWindow) {
                    window = currentWindow;
                    start = L;
                }
                mpS[s[L++]]--;
            }
        }
        if (window == INT_MAX)
            return ans;
        return s.substr(start, window);
    }
};