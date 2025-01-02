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

    ListNode* getMiddle(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast->next;
            if(fast != NULL){
                fast = fast->next;
                slow = slow->next;
            }
        }
        return slow;
    }

    ListNode* reverseList(ListNode* prev,ListNode* curr){
        while(curr != NULL){
            ListNode* forward = curr->next;
            curr->next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }

    bool compareLists(ListNode* head1, ListNode* head2){
        while(head1 != NULL){
            if(head1->val == head2->val){
                head1 = head1->next;
                head2 = head2->next;
            } else {
                return false;
            }
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        ListNode* middle = getMiddle(head);
        ListNode* temp = head;
        while(temp && temp->next != middle){
            temp = temp->next;
        }
        if(temp){
            temp->next = NULL;
        }
        ListNode* prev = NULL;
        ListNode* newHead = reverseList(prev, middle);
        return compareLists(head, newHead);
    }
};