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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* p=l1,*q=l2;
        if(p==NULL) return q;
        if(q==NULL) return p; 
        ListNode* head=new ListNode(0);
        ListNode* pos=head;
        while(p!=NULL&&q!=NULL) {
            if(p->val<q->val) {
                pos->next=p;
                pos=pos->next;
                p=p->next;
            }
            else {
                pos->next=q;
                pos=pos->next;
                q=q->next;
            }
        }
        if(p==NULL) pos->next=q;
        else pos->next=p;
        return head->next;
        
    }
};