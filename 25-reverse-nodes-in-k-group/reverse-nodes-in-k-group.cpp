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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (!head || k == 1) return head;
        
        // Dummy node helps handle the head change easily
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* curr = dummy;
        ListNode* nex = dummy;
        ListNode* pre = dummy;
        
        // Count total number of nodes in the linked list
        int count = 0;
        while (curr->next) {
            curr = curr->next;
            count++;
        }
        
        // Loop through the list, reversing chunks of size k
        while (count >= k) {
            curr = pre->next;
            nex = curr->next;
            
            // Standard in-place reversal for k-1 links within the group
            for (int i = 1; i < k; i++) {
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            // Move pre pointer to the tail of the sublist just reversed
            pre = curr;
            count -= k;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up the dummy node
        return newHead;
        
    }
};