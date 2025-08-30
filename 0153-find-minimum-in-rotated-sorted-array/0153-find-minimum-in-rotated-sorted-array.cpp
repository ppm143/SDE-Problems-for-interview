class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0, e = nums.size() - 1, m;
        int ans = nums[0];

        while (s <= e) {
            m = s + (e - s) / 2;
            if (nums[0] <= nums[m])
                s = m + 1;
            else {
                e = m - 1;
                ans = min(ans, nums[m]);
            }
        }
        return ans;
    }
};