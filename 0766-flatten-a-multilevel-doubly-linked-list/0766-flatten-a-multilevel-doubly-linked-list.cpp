/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flattenAndGetChild(Node* head){
        if(!head) return nullptr;
        Node* temp = head;
        Node* childTail = nullptr;
        while(temp){
            if(temp->child){
                childTail = flattenAndGetChild(temp->child);
                // adjust pointer after flattening
                childTail->next = temp->next;
                if(temp->next) temp->next->prev = childTail;
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = nullptr;
            }
            childTail = temp;
            temp = temp->next;
        }
        return childTail;
    }
    Node* flatten(Node* head) {
        flattenAndGetChild(head);
        return head;
    }
};