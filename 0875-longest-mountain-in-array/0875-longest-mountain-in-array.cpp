class Solution {
public:
    int longestMountain(vector<int>& a) {
        int ans = 0, i = 1, n = a.size();
        while (i < n) {
            int peak = 0, valley = 0;
            while (i < n and a[i] > a[i - 1])
                peak++, i++;
            while (i < n and a[i] < a[i - 1])
                valley++, i++;

            if (peak > 0 and valley > 0)
                ans = max(ans, valley + peak + 1);
            if (!peak and !valley)
                i++;
        }
        return ans;
    }
};