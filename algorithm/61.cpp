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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* pre=head,*pos=head->next;
        ListNode* pend=head;
        int n=1;
        while(pend->next!=NULL) {
            pend=pend->next;
            n++;
        }
        k=k%n;
        if(k==0) return head;
        else {
            for(int i=n-k;i>1;i--) {
                pre=pre->next;
                pos=pos->next;
            }
            pend->next=head;
            pre->next=NULL;
            return pos;
        }

    }
};