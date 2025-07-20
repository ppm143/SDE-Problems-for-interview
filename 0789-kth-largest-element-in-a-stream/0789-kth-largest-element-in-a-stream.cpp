class KthLargest {
public:
    priority_queue<int, vector<int>, greater<int>> minQ;
    int k_size;
    KthLargest(int k, vector<int>& nums) {
        k_size = k;
        for (int& num : nums) {
            minQ.push(num);
            if (minQ.size() > k)
                minQ.pop();
        }
    }

    int add(int val) {
        minQ.push(val);
        if (minQ.size() > k_size)
            minQ.pop();
        return minQ.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */