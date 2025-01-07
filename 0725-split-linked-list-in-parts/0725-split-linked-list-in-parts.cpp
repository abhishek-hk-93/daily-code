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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // get length, part size and number of extra nodes
        int length = 0;
        ListNode* temp = head;
        while(temp){
            temp = temp->next;
            length++;
        }
        int partSize = length / k;
        int extraNodes = length % k;
        temp = head;

        // iterate through Linked List and divide them into buckets
        vector<ListNode*> ans(k, nullptr);
        for(int i=0; i<k && temp; i++){
            ans[i] = temp;
            int extendedPartSize = partSize + (extraNodes-- > 0 ? 1 : 0);
            for(int j=0; j<extendedPartSize-1; j++)
                temp = temp->next;
            ListNode* nextPartStartNode = temp->next;
            temp->next = nullptr;
            temp = nextPartStartNode;
        }

        return ans; 
    }
};