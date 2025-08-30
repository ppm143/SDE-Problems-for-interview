/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> oldToCopy;
        oldToCopy[nullptr] = nullptr;
        Node* curr = head;
        while (curr != nullptr) {
            Node* copy = new Node(curr->val);
            oldToCopy[curr] = copy;
            curr = curr->next;
        }
        curr = head;
        while (curr != nullptr) {
            Node* copy = oldToCopy[curr];
            copy->next = oldToCopy[curr->next];
            copy->random = oldToCopy[curr->random];
            curr = curr->next;
        }
        return oldToCopy[head];
    }
};