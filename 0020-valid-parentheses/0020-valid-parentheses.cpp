class Solution {
    bool isValid(char &a, char &b) {
        return (a == '(' and b == ')') or (a == '[' and b == ']') or
               (a == '{' and b == '}');
    }
    bool isOpen(char &a) { return a == '(' or a == '[' or a == '{'; }

public:
    bool isValid(string s) {
        stack<char> st;
        for (char& ch : s) {
            if (isOpen(ch) or st.empty())
                st.push(ch);
            else if (isValid(st.top(), ch))
                st.pop();
            else
                return false;
        }
        return st.empty();
    }
};