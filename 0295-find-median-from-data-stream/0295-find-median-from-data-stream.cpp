class MedianFinder {
public:
    priority_queue<int> maxQ;
    priority_queue<int, vector<int>, greater<int>> minQ;
    MedianFinder() {}

    void addNum(int num) {
        maxQ.push(num);
        minQ.push(maxQ.top());
        maxQ.pop();
        if (minQ.size() > maxQ.size()) {
            maxQ.push(minQ.top());
            minQ.pop();
        }
    }

    double findMedian() {
        if (maxQ.size() > minQ.size())
            return maxQ.top();

        return (maxQ.top() + minQ.top()) / 2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */