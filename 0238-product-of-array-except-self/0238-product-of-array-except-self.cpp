class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 1);
        int LP = 1, RP = 1;
        for (int i = 0; i < n; i++) {
            ans[i] *= LP;
            LP *= nums[i];
        }
        for (int i = n - 1; i >= 0; i--) {
            ans[i] *= RP;
            RP *= nums[i];
        }
        return ans;
    }
};