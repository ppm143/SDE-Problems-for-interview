class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        int ans = 0, count = 0;
        for (int& num : nums) {
            if (num == mx)
                ans = max(ans, ++count);
            else
                count = 0;
        }
        return ans;
    }
};