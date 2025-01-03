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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* prevNode = head;
        ListNode* temp;
        while(prevNode->next != NULL){
            temp = prevNode->next;
            if(temp->val == prevNode->val){
                prevNode->next = temp->next;
                temp->next = NULL;
                delete temp;
            }else {
                prevNode = prevNode->next;
                temp = temp->next;
            }
        }
        return head;
    }
};