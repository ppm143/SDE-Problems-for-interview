class Solution {
public:
    bool checkValidString(string s) {
        int cMin = 0, cMax = 0;
        for (char ch : s) {
            if (ch == '(')
                cMax++, cMin++;
            if (ch == ')')
                cMax--, cMin = max(cMin - 1, 0);
            if (ch == '*')
                cMax++, cMin = max(cMin - 1, 0);

            if (cMax < 0)
                return false;
        }
        return cMin == 0;
    }
};