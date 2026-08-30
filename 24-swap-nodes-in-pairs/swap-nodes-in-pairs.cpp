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
    ListNode* swapPairs(ListNode* head) {
        ListNode* curr = head;
        ListNode* f = head;
        ListNode* s = NULL;
        ListNode* p = NULL;
        ListNode* n = NULL;
        if (head && head->next)
            head = head->next;
        while (f) {

            // update vals;
            if (f->next)
                s = f->next;
            else
                break;
            if (s) {
                n = s->next;
            }

            // swap
            if (p)
                p->next = s;
            if (f)
                f->next = n;
            if (s)
                s->next = f;

            // next iteration
            p = f;
            f = n;
        }
        return head;
    }
};