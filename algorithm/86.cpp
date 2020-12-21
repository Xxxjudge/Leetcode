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
    ListNode* partition(ListNode* head, int x) {
        ListNode* before=new ListNode(0);
        ListNode* after=new ListNode(0);
        ListNode* p=before,*q=after;
        while(head!=NULL) {
            if(head->val<x) {
                p->next=head;
                head=head->next;
                p=p->next;
            } else {
                q->next=head;
                head=head->next;
                q=q->next;
            }
        }
        q->next=NULL;//多了这一行就行了？？？
        p->next=after->next;
        return before->next;
    }
};