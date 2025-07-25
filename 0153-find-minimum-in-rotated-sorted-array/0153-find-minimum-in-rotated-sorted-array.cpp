class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, ans = -1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[right] > nums[mid]) {
                right = mid;
            } else
                ans = mid, left = mid + 1;
        }
        return nums[ans];
    }
};