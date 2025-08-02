class Solution {
public:
    long long minCost(vector<int>& b1, vector<int>& b2) {
        unordered_map<int, int> mp;
        for (int& nm : b1)
            mp[nm]++;
        for (int& nm : b2)
            mp[nm]--;

        vector<int> toSwap;
        int mn = INT_MAX;

        for (auto& [nm, freq] : mp) {
            mn = min(nm, mn);
            if (freq % 2)
                return -1;
            for (int i = 0; i < abs(freq) / 2; i++)
                toSwap.push_back(nm);
        }
        sort(toSwap.begin(), toSwap.end());
        long long ans = 0;
        for (int i = 0; i < toSwap.size() / 2; i++) {
            ans += min(1L * toSwap[i], 2L * mn);
        }
        return ans;
    }
};