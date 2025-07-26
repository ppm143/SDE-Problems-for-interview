class FindSumPairs {
    unordered_map<int, int> mp1, mp2;
    vector<int> nm1, nm2;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nm1 = nums1;
        this->nm2 = nums2;

        for (int& num : nums1)
            mp1[num]++;
        for (int& num : nums2)
            mp2[num]++;
    }

    void add(int index, int val) {
        int x = nm2[index];
        mp2[x]--;
        if (mp2[x] == 0)
            mp2.erase(x);
        nm2[index] += val;
        mp2[x + val]++;
    }

    int count(int tot) {
        int cnt = 0;
        for (auto& [num1, freq] : mp1) {
            if (mp2.find(tot - num1) != mp2.end() && mp2[tot - num1] > 0) {
                cnt += (freq * mp2[tot - num1]);
            }
        }
        return cnt;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */