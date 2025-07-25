class Solution {
    bool isPossible(vector<int>& piles, int k, int h) {
        long long count = 0;
        for (int& pile : piles) {
            count += (long long)pile / k;
            count += pile % k ? 1 : 0;
        }
        return count <= h;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end()), ans = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (isPossible(piles, mid, h)) {
                ans = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};