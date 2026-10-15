class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *slow = head, *fast = head->next;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* left = sortList(head);
        ListNode* right = sortList(mid);
        ListNode dummy(0);
        ListNode* cur = &dummy;
        while (left && right) {
            if (left->val < right->val) { cur->next = left; left = left->next; }
            else { cur->next = right; right = right->next; }
            cur = cur->next;
        }
        cur->next = left ? left : right;
        return dummy.next;
    }
};