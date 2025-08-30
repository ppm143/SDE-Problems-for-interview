class Solution {
public:
    int jump(vector<int>& nums) {
        int start = 0, end = 0, minJump = 0;
        int farthest = 0;
        while (end < nums.size() - 1) {
            for (int i = start; i <= end; i++)
                farthest = max(farthest, i + nums[i]);
            minJump++;
            start = end + 1;
            end = farthest;
        }
        return minJump;
    }
};