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
    Node* flattenWithChild(Node* node){
        if(!node) return nullptr;
        Node* temp = node;
        Node* childTail = temp;
        while(temp){
            if(temp->child){
                childTail = flattenWithChild(temp->child);
                childTail->next = temp->next;
                if(temp->next) temp->next->prev = childTail;
                temp->next = temp->child;
                temp->next->prev = temp;
                temp->child = nullptr;
            }
            // always keep track of prev to temp, required when temp becomes null
            childTail = temp;
            temp = temp->next;
        }
        return childTail;
    }
    Node* flatten(Node* head) {
        flattenWithChild(head);
        return head;
    }
};