class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s = 0;
        int n = fruits.size();
        int ans = 0;
        unordered_map<int, int> mp;

        for (int e = 0; e < n; e++) {
            mp[fruits[e]]++;
            while (mp.size() > 2) {
                mp[fruits[s]]--;
                if (mp[fruits[s]] == 0)
                    mp.erase(fruits[s]);
                s++;
            }
            ans = max(ans, e - s + 1);
        }
        return ans;
    }
};