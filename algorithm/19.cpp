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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* header=new ListNode(0);
        header->next=head;
        ListNode* p=header;
        ListNode* pre=header;
        for(int i=0;i<n+1;i++) {
            if(p->next==NULL) return head->next;
            p=p->next;
        }
        while(p!=NULL) {
            p=p->next;
            pre=pre->next;
        }
        pre->next=pre->next->next;
        return head;
    }
};