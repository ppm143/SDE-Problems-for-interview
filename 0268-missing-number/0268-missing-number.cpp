class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int missing = 0, n = nums.size();

        for (int i = 0; i < n; i++) {
            missing ^= nums[i];
            missing ^= i;
        }
        missing ^= n;
        return missing;
    }
};