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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* a=temp,*b=head;
        while(b!=NULL&&b->next!=NULL) {
            if((a->next!=NULL)&&(b->next!=NULL)&&a->next->val!=b->next->val) {
                a=a->next;
                b=b->next;
            } else {
                while((a->next!=NULL)&&(b->next!=NULL)&&a->next->val==b->next->val)
                    b=b->next;
                b=b->next;
                a->next=b;
            }
        }
        a->next=b;
        return temp->next;
    }
};