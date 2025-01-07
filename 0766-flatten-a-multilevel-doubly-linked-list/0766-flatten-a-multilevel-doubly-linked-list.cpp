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
    Node* getChildTail(Node* node){
        if(!node) return nullptr;
        Node* temp = node;
        Node* childTail = temp;
        while(temp){
            if(temp->child){
                childTail = getChildTail(temp->child);
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
        getChildTail(head);
        return head;
    }
};