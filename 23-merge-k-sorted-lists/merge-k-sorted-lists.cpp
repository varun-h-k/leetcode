class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Custom comparator for the min-heap
        auto cmp = [](ListNode* a, ListNode* b) {
            return a->val > b->val; 
        };

        std::priority_queue<ListNode*, std::vector<ListNode*>, decltype(cmp)> minHeap(cmp);

        // Push the head of each non-empty linked list into the min-heap
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        // Extract the minimum node and push its next node into the heap
        while (!minHeap.empty()) {
            ListNode* smallest = minHeap.top();
            minHeap.pop();

            tail->next = smallest;
            tail = tail->next;

            if (smallest->next != nullptr) {
                minHeap.push(smallest->next);
            }
        }

        return dummy.next;
    }
};

