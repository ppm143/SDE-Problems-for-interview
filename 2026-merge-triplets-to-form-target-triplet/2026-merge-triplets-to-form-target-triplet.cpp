class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        unordered_set<int> good;

        for (auto& t : triplets) {
            if (t[0] > target[0] or t[1] > target[1] or t[2] > target[2])
                continue;

            for (int i = 0; i < t.size(); i++) {
                if (t[i] == target[i])
                    good.insert(i);
            }
        }

        return good.size() == 3;
    }
};