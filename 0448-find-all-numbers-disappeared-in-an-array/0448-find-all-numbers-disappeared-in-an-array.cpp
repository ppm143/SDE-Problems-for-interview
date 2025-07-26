class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int idx = abs(nums[i]) - 1;
            while (nums[idx] > 0) {
                nums[idx] = -nums[idx];
                idx = abs(nums[idx]) - 1;
            }
        }

        vector<int> ans;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0)
                ans.push_back(i + 1);
        }
        return ans;
    }
};