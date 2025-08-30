class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        long long currZero = 0;
        for (int& num : nums) {
            if (num == 0)
                currZero++;
            else
                currZero = 0;
            ans += currZero;
        }
        return ans;
    }
};