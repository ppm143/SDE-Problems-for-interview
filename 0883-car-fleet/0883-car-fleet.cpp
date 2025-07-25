class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, int>> cars;
        int n = position.size();
        for (int i = 0; i < n; i++)
            cars.push_back({position[i], speed[i]});

        sort(cars.begin(), cars.end());
        stack<double> st;

        for (int i = n - 1; i >= 0; i--) {
            auto [p, s] = cars[i];
            double t = (target - p) / (double)s;
            if (st.empty() or st.top() < t)
                st.push(t);
        }
        return st.size();
    }
};