/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return root;
        queue<Node*> Q;
        Q.push(root);

        while (!Q.empty()) {
            int qSize = Q.size();
            for (int i = 0; i < qSize; i++) {
                Node* currNode = Q.front();
                Q.pop();
                if (i == qSize - 1) {
                    currNode->next = nullptr;
                } else {
                    currNode->next = Q.front();
                }
                if (currNode->left)
                    Q.push(currNode->left);
                if (currNode->right)
                    Q.push(currNode->right);
            }
        }
        return root;
    }
};