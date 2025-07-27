class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (char& ch : tasks)
            mp[ch]++;

        priority_queue<int> maxQ;

        for (auto& [ch, freq] : mp)
            maxQ.push(freq);

        int alltime = 0, cycle = n + 1, workTime;
        while (!maxQ.empty()) {
            workTime = 0;
            vector<int> Q;
            for (int i = 0; i < cycle; i++) {
                if (!maxQ.empty()) {
                    Q.push_back(maxQ.top());
                    maxQ.pop();
                    workTime++;
                }
            }
            for (int& freq : Q) {
                if (--freq)
                    maxQ.push(freq);
            }
            alltime += !maxQ.empty() ? cycle : workTime;
        }
        return alltime;
    }
};