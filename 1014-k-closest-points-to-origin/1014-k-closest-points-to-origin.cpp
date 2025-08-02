class Solution {
    struct compareByDistance {
        bool operator()(vector<int>& p, vector<int>& q) {
            return p[0] * p[0] + p[1] * p[1] < q[0] * q[0] + q[1] * q[1];
        }
    };

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>, vector<vector<int>>, compareByDistance>
            minQ;
        for (vector<int>& point : points) {
            minQ.push(point);
            if (minQ.size() > k) {
                minQ.pop();
            }
        }

        vector<vector<int>> ans;
        while (!minQ.empty()) {
            ans.push_back(minQ.top());
            minQ.pop();
        }
        return ans;
    }
};