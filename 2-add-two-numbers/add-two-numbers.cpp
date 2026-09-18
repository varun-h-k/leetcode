class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy head to easily attach new nodes to the result list
        ListNode* dummyHead = new ListNode(0);
        ListNode* current = dummyHead;
        int carry = 0;
        
        // Loop until both lists are empty and there is no remaining carry
        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int sum = carry; // Start with the carry from the previous step
            
            // Add value from l1 if it exists
            if (l1 != nullptr) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            // Add value from l2 if it exists
            if (l2 != nullptr) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Calculate new carry and the digit to store in the node
            carry = sum / 10;
            current->next = new ListNode(sum % 10);
            
            // Move the pointer forward
            current = current->next;
        }
        
        ListNode* result = dummyHead->next;
        delete dummyHead; // Free the memory allocated for dummy head
        return result;
    }
};