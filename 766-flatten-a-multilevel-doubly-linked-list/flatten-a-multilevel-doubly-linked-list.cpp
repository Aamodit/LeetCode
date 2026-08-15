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
    Node* s(Node* head) {
        Node* curr = head;
        Node* last = curr;
        while (curr != NULL) {
            if (curr->child) {
                Node* nextNode = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                Node* tail = s(curr->child);
                if (nextNode) {
                    nextNode->prev = tail;
                }
                tail->next = nextNode;
                curr->child = NULL;
            }
            curr = curr->next;
            if (curr)
                last = curr;
        }
        return last;
    }
    Node* flatten(Node* head) {
        s(head);
        return head;
    }
};