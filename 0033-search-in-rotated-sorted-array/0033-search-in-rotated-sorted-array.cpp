class Solution {
public:
    int search(vector<int>& a, int k) {
        int s = 0, e = a.size() - 1, m;
        while (s <= e) {
            m = s + (e - s) / 2;
            if (a[m] == k)
                return m;
            if (a[s] <= a[m]) {
                if (a[s] <= k and k <= a[m])
                    e = m - 1;
                else
                    s = m + 1;
            } else {
                if (a[m] <= k and k <= a[e])
                    s = m + 1;
                else
                    e = m - 1;
            }
        }
        return -1;
    }
};