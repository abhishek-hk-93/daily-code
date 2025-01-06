/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        // Using map
        /*unordered_map<ListNode* , bool> m;
        ListNode* temp = head;
        while(temp != NULL){
            if(m[temp] == true){
                return temp;
            } else{
                m[temp] = true;
                temp = temp->next;
            }
        }
        return NULL;
        */

        // O(1) space - slow fast pointer method

        ListNode* slow = head;
        ListNode* fast = head;
        while(slow != NULL && fast != NULL){
            slow = slow->next ? slow->next : NULL;
            fast = fast->next && fast->next->next ? fast->next->next : NULL;
            if(slow == fast){
                break;
            }
        }
        slow = head;
        while(slow != NULL && fast != NULL){
            if(slow == fast){
                return slow;
            }
            slow = slow->next ? slow->next : NULL;
            fast = fast->next ? fast->next : NULL;
        }
        return NULL;
    }
};