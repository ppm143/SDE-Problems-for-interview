class Solution {
    bool isValidWindow(unordered_map<char, int>& mp1,
                       unordered_map<char, int>& mp2) {
        for (char ch = 'a'; ch <= 'z'; ch++) {
            if (mp1[ch] > mp2[ch])
                return false;
        }
        return true;
    }

public:
    bool checkInclusion(string s1, string s2) {
        int L = 0;
        int ss1 = s1.size(), ss2 = s2.size();
        if (ss1 > ss2)
            return false;
        unordered_map<char, int> mps1, mps2;
        for (int i = 0; i < ss1; i++)
            mps1[s1[i]]++, mps2[s2[i]]++;
        if (isValidWindow(mps1, mps2))
            return true;

        for (int i = ss1; i < ss2; i++) {
            mps2[s2[i - ss1]]--;
            mps2[s2[i]]++;
            if (isValidWindow(mps1, mps2))
                return true;
        }
        return false;
    }
};