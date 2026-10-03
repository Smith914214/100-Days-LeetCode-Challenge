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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        // Edge case: if no reversal or list is single-element
        if (!head || left == right) return head;
        
        // Dummy node to easily handle left = 1 edge cases
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        // Step 1: Reach the node just before the sublist starting position
        ListNode* prev = dummy;
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }
        
        // Step 2: Reverse the sublist from left to right positions
        ListNode* curr = prev->next; 
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        
        // Clean up dummy reference and return new head
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};