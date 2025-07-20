class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int& num : nums)
            mp[num]++;
        int n = nums.size();
        vector<vector<int>> buckets(n + 1, vector<int>());
        for (auto& [num, count] : mp)
            buckets[count].push_back(num);

        vector<int> ans;
        for (int i = n; i >= 1 and k; i--) {
            for (int x : buckets[i]) {
                ans.push_back(x);
                k--;
                if (k == 0)
                    break;
            }
        }
        return ans;
    }
};