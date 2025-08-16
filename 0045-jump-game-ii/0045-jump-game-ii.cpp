class Solution {
public:
    int jump(vector<int>& nums) {
        int l = 0, r = 0, ans = 0;
        int farthest = 0;
        while (r < nums.size() - 1) {
            for (int i = l; i <= r; i++)
                farthest = max(farthest, i + nums[i]);
            ans++;
            l = r + 1;
            r = farthest;
        }
        return ans;
    }
};