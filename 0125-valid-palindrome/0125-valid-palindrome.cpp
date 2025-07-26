class Solution {
public:
    bool isPalindrome(string ss) {
        int s = 0, e = ss.length() - 1;
        while (s < e) {
            while (s < e and !isalnum(ss[s]))
                s++;
            while (s < e and !isalnum(ss[e]))
                e--;
            char sch = tolower(ss[s]);
            char ech = tolower(ss[e]);
            if (sch != ech) {
                return false;
            }
            s++;
            e--;
        }
        return true;
    }
};