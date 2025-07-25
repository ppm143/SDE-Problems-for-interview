class MinStack {
    stack<pair<int, int>> minStk;

public:
    MinStack() {}

    void push(int val) {
        if (minStk.empty())
            minStk.push({val, val});
        else {
            minStk.push({val, min(val, minStk.top().second)});
        }
    }

    void pop() { minStk.pop(); }

    int top() { return minStk.top().first; }

    int getMin() { return minStk.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */