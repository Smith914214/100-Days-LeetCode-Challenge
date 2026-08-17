/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(x) : val(x), next(nullptr) {}
 *     ListNode(x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        // Base case: if list has 0 or 1 node, no swapping needed
        if (!head || !head->next) return head;
        
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        
        while (prev->next && prev->next->next) {
            ListNode* first = prev->next;
            ListNode* second = prev->next->next;
            
            // Adjusting pointers to swap the two nodes
            first->next = second->next;
            second->next = first;
            prev->next = second;
            
            // Move prev pointer two steps ahead for the next pair
            prev = first;
        }
        
        ListNode* newHead = dummy->next;
        delete dummy; // Clean up memory
        return newHead;
    }
};