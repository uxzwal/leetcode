/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == nullptr || headB == nullptr) return nullptr;
        
        ListNode *pA = headA;
        ListNode *pB = headB;
        
        // Loop terminates either at the intersection node or at nullptr (no intersection)
        while (pA != pB) {
            // If pA reaches the end, redirect it to headB; otherwise, move to next node
            pA = (pA == nullptr) ? headB : pA->next;
            // If pB reaches the end, redirect it to headA; otherwise, move to next node
            pB = (pB == nullptr) ? headA : pB->next;
        }
        
        return pA;
    }
};
