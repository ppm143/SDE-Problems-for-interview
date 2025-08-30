class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalGas = 0, ans = 0;

        if (accumulate(gas.begin(), gas.end(), 0) <
            accumulate(cost.begin(), cost.end(), 0))
            return -1;

        for (int i = 0; i < cost.size(); i++) {
            totalGas += (gas[i] - cost[i]);
            if (totalGas < 0) {
                totalGas = 0;
                ans = i + 1;
            }
        }
        return ans;
    }
};