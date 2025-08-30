/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty())
            return nullptr;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };

        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> minQ(cmp);

        for (ListNode* list : lists) {
            if (list != nullptr)
                minQ.push(list);
        }

        ListNode* res = new ListNode(0);
        ListNode* curr = res;

        while (!minQ.empty()) {
            ListNode* node = minQ.top();
            minQ.pop();

            curr->next = node;
            curr = curr->next;

            if (node->next != nullptr)
                minQ.push(node->next);
        }
        return res->next;
    }
};