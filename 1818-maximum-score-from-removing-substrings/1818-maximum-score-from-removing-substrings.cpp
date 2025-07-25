class Solution {
    string greedy(string s, char a, char b) {
        string st;
        for (char& ch : s) {
            if (!st.empty() && st.back() == a && ch == b)
                st.pop_back();
            else
                st.push_back(ch);
        }
        return st;
    }

public:
    int maximumGain(string s, int x, int y) {
        char a = 'a';
        char b = 'b';
        if (y > x) {
            swap(x, y);
            swap(a, b);
        }
        string s1 = greedy(s, a, b);
        string s2 = greedy(s1, b, a);

        int ab = ((s.size() - s1.size()) / 2) * x;
        int ba = ((s1.size() - s2.size()) / 2) * y;
        return ab + ba;
    }
};