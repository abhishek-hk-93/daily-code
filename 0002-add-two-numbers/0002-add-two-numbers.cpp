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
    ListNode* addRecursively(ListNode* l1, ListNode* l2, int carry=0){
        if(!l1 && !l2 && !carry) return 0;

        int num1 = l1 ? l1->val : 0;
        int num2 = l2 ? l2->val : 0;
        int sum = num1 + num2 + carry;
        int digit = sum % 10;
        carry = sum / 10;
        ListNode* newNode = new ListNode(digit);
        newNode->next = addRecursively(l1 ? l1->next : l1, l2 ? l2->next : l2, carry);
        return newNode;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // recursive
        return addRecursively(l1, l2);
        // Iterative
        /*
        ListNode* temp = new ListNode(-1);
        ListNode* sumList = temp;

        int carry = 0;
        while(l1 || l2 || carry){
            int num1 = l1 ? l1->val : 0;
            int num2 = l2 ? l2->val : 0;
            int sum = num1 + num2 + carry;
            int digit = sum % 10;
            carry = sum / 10;
            ListNode* newNode = new ListNode(digit);
            temp->next = newNode;
            temp = temp->next;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        return sumList->next;
        */
    }
};