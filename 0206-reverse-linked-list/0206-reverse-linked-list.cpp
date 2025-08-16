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
    ListNode* reverseListIterative(ListNode* head) {
        ListNode *curr = head, *next = nullptr, *prev = nullptr;

        while (curr != nullptr) {
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
        if (!head)
            return prev;
        ListNode* next = head -> next;
        head -> next = prev;
        return reverseList(next, head);
    }
};