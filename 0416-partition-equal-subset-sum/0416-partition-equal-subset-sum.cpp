class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum & 1)
            return false;

        int target = sum / 2;
        unordered_set<int> dp, nextDp;
        dp.insert(0);
        for (int i = 0; i < n; i++) {
            nextDp.clear();
            for (int t : dp) {
                if (t + nums[i] == target)
                    return true;
                nextDp.insert(t + nums[i]);
                nextDp.insert(t);
            }
            dp = nextDp;
        }
        return false;
    }
};