class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode * pre=nullptr;
        ListNode * p=head;
        while(p!=nullptr) {
            if(p->val==val) {
                if(pre!=nullptr) pre->next=p->next;
                else head=p->next;
                p=p->next;  
            } else{
                pre=p;
                p=p->next;  
            }
          
        }
        return head;
    }
};