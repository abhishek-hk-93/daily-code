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

    ListNode* reverseRecursively(ListNode* &prev, ListNode* curr){
        if(curr == NULL){
            return prev;
        }
        ListNode* forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        return reverseRecursively(prev, curr);
    }
    ListNode* reverseList(ListNode* head) {
        
        /* Recursive solution 
        ListNode* prev = NULL;
        ListNode* curr = head;
        return reverseRecursively(prev, curr);
        */

        ListNode* prev = NULL;
        while(head != NULL){
            ListNode* forward = head->next;
            head->next = prev;
            prev = head;
            head = forward;
        }
        return prev;
    }
};