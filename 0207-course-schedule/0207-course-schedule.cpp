class Solution {
    bool bfs(queue<int>& Q, vector<int>& indegree, vector<vector<int>>& adj,
             int numberOfCourses) {

        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            for (int& curr : adj[node]) {
                indegree[curr]--;
                if (indegree[curr] == 0) {
                    Q.push(curr);
                    numberOfCourses--;
                }
            }
        }
        return numberOfCourses == 0;
    }

    bool isCycleDFS(int node, vector<vector<int>>& adj, vector<bool>& vis,
                    vector<bool>& dfsVis) {
        vis[node] = 1;
        dfsVis[node] = 1;
        for (auto child : adj[node]) {
            if (!vis[child]) {
                if (isCycleDFS(child, adj, vis, dfsVis))
                    return true;
            } else if (dfsVis[child])
                return true;
        }
        dfsVis[node] = 0;
        return false;
    }

public:
    bool canFinish(int N, vector<vector<int>>& P) {
        vector<vector<int>> adj(N);
        vector<int> indegree(N, 0);
        int numberOfCourses = N;
        for (auto& x : P) {
            int u = x[0], v = x[1];
            adj[v].push_back(u);
            indegree[u]++;
        }
        queue<int> Q;
        for (int i = 0; i < N; i++) {
            if (indegree[i] == 0) {
                Q.push(i);
                numberOfCourses--;
            }
        }
        return bfs(Q, indegree, adj, numberOfCourses);
    }
};