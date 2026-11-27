#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (ListNode* list : lists) {
            if (list) {
                pq.push(list);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {
            ListNode* curr = pq.top();
            pq.pop();
            tail->next = curr;
            tail = tail->next;

            if (curr->next) {
                pq.push(curr->next);
            }
        }

        return dummy.next;
    }
};
