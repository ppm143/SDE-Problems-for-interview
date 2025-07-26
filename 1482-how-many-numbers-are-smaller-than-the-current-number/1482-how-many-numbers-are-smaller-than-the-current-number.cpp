class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<int> temp(nums.begin(), nums.end());
        sort(temp.begin(), temp.end());
        for (int i = 0; i < temp.size(); i++) {
            if (mp.find(temp[i]) != mp.end())
                continue;
            mp[temp[i]] = i;
        }
        vector<int> ans;
        for (int& num : nums)
            ans.emplace_back(mp[num]);
        return ans;
    }
};