class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int s = 0, e = nums.size() - 1;
        while (s < e) {
            int sum = nums[s] + nums[e];
            if (sum == target)
                return {s + 1, e + 1};
            else if (sum < target)
                s++;
            else
                e--;
        }
        return {};
    }
};