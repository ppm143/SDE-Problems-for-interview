class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> st;
        int num = n, sum = 0, d;
        while (sum != 1) {
            sum = 0;
            while (num) {
                d = num % 10;
                num /= 10;
                sum += d * d;
            }
            if (st.contains(sum))
                return false;
            st.insert(sum);
            num = sum;
        }
        return sum == 1;
    }
};