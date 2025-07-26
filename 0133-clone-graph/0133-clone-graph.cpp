/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    Node* bfs(Node* node) {
        if (!node)
            return nullptr;
        unordered_map<Node*, Node*> oldToNew;
        oldToNew[node] = new Node(node->val);
        queue<Node*> Q;
        Q.push(node);
        while (!Q.empty()) {
            Node* node = Q.front();
            Q.pop();
            for (auto nbr : node->neighbors) {
                if (oldToNew.find(nbr) == oldToNew.end()) {
                    Q.push(nbr);
                    oldToNew[nbr] = new Node(nbr->val);
                }
                oldToNew[node]->neighbors.push_back(oldToNew[nbr]);
            }
        }
        return oldToNew[node];
    }

    // using DFS
    unordered_map<Node*, Node*> oldToNew;
    Node* dfs(Node* node) {
        if (!node)
            return nullptr;
        if (oldToNew.find(node) == oldToNew.end()) {
            oldToNew[node] = new Node(node->val);
            for (Node* nbr : node->neighbors) {
                oldToNew[node]->neighbors.push_back(dfs(nbr));
            }
        }
        return oldToNew[node];
    }

public:
    Node* cloneGraph(Node* node) { return bfs(node); }
};