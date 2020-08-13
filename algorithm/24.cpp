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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* p=head;
        ListNode* q=head->next;
        head=q;
        while(p!=NULL&&q!=NULL) {
            p->next=q->next;
            q->next=p;
            if(p->next!=NULL) {
                p=p->next;
                q=p->next;
            }
            else return head;
        }
        return head;
    }
};