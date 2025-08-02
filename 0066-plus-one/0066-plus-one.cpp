class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        vector<int> ans;
        for (int i = digits.size() - 1; i >= 0; i--) {
            int d = (digits[i] + carry) % 10;
            carry = (digits[i] + carry) / 10;
            ans.push_back(d);
        }
        if (carry)
            ans.push_back(carry);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};