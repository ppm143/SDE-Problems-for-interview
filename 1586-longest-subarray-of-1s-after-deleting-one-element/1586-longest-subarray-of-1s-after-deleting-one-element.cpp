class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        int currZero = 0;
        int s = 0;
        for (int e = 0; e < n; e++) {
            currZero += !nums[e];
            while (currZero > 1) {
                currZero -= !nums[s];
                s++;
            }
            ans = max(ans, e - s);
        }
        return ans;
    }
};