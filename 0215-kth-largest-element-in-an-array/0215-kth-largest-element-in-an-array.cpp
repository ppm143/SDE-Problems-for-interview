class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> minQ;
        for (int& num : nums) {
            minQ.push(num);
            if (minQ.size() > k)
                minQ.pop();
        }
        return minQ.top();
    }
};