class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *prev = nullptr, *cur = slow->next;
        slow->next = nullptr;
        while (cur) {
            ListNode *nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        ListNode *first = head, *second = prev;
        while (second) {
            ListNode *tmp1 = first->next, *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};
