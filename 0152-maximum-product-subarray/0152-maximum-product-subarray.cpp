class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMin = 1, currMax = 1, ans = nums[0];

        for (int& num : nums) {
            int temp = currMax;
            currMax = max({currMax * num, num, currMin * num});
            currMin = min({temp * num, num, currMin * num});
            ans = max(ans, currMax);
        }
        return ans;
    }
};