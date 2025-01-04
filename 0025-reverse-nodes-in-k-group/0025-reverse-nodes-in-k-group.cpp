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
    int getLength(ListNode* head){
        int len = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        return len;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL || head->next == NULL || k < 2){
            return head;
        }
        int len = getLength(head);

        if(len < k){
            return head;
        }

        // reverse list from head to k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        int counter = 0;
        while(counter < k && curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
            counter++;
        }
        if(curr != NULL){
            ListNode* recHead = reverseKGroup(curr, k);
            head->next = recHead;
        }

        return prev;
    }
};