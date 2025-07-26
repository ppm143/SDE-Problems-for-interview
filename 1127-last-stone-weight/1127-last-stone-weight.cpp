class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxQ;
        for (int& num : stones)
            maxQ.push(num);

        while (maxQ.size() > 1) {
            int x = maxQ.top();
            maxQ.pop();
            int y = maxQ.top();
            maxQ.pop();
            if (x == y)
                continue;
            maxQ.push(abs(x - y));
        }
        if (maxQ.empty())
            return 0;
        return maxQ.top();
    }
};