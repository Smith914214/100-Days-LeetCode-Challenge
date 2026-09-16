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
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes to ease list manipulation
        ListNode lessHead(0); 
        ListNode greaterHead(0);
        
        // Pointers to track the end of both lists
        ListNode* less = &lessHead;
        ListNode* greater = &greaterHead;
        
        // Traverse the original list
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        // Prevent cycles by terminating the greater list
        greater->next = nullptr;
        
        // Connect the less list to the greater list
        less->next = greaterHead.next;
        
        return lessHead.next;
    }
};