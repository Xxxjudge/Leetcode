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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        int sum=0;
        ListNode* head=new ListNode(0);
        ListNode* p=l1;
        ListNode* q=l2;
        ListNode* ans=head;
        while(p!=NULL||q!=NULL)
        {      
            if(p!=NULL)
            {
                sum+=p->val;
                p=p->next;
            }   
            if(q!=NULL)
            {
                sum+=q->val;
                q=q->next;
            }
            if(carry)
            sum+=1;
            ans->next=new ListNode(sum%10);
            ans=ans->next;
            carry=(sum/10==1)?1:0;
            sum=0;
        }
        if(carry)
        {
            ans->next=new ListNode(1);
            ans->next->next=NULL;
        }
        return head->next;
    }
};