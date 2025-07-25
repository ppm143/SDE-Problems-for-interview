class Solution {
    int calc(int a, int b, string s) {
        if (s == "+")
            return a + b;
        else if (s == "*")
            return a * b;
        else if (s == "-")
            return a - b;
        else
            return a / b;
    }
    bool isOp(string s) { return s == "+" or s == "-" or s == "/" or s == "*"; }

public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for (string& s : tokens) {
            if (st.empty() or !isOp(s)) {
                st.push(stoi(s));
            } else {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                int nm = calc(x, y, s);
                st.push(nm);
            }
        }
        return st.top();
    }
};