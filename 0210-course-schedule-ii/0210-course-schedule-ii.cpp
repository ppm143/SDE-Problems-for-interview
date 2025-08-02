class Solution {
    vector<int> bfs(queue<int>& Q, vector<int>& indegrees,
                    vector<vector<int>>& adj) {

        vector<int> ans;
        while (!Q.empty()) {
            int node = Q.front();
            Q.pop();
            ans.push_back(node);
            for (int& nbr : adj[node]) {
                indegrees[nbr]--;
                if (indegrees[nbr] == 0)
                    Q.push(nbr);
            }
        }
        return ans;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        queue<int> Q;
        vector<int> indegrees(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for (vector<int>& prerequisite : prerequisites) {
            int u = prerequisite[0];
            int v = prerequisite[1];
            adj[v].push_back(u);
            indegrees[u]++;
        }

        for (int i = 0; i < indegrees.size(); i++) {
            if (indegrees[i] == 0)
                Q.push(i);
        }

        vector<int> ans = bfs(Q, indegrees, adj);
        if (ans.size() == numCourses)
            return ans;

        return {};
    }
};