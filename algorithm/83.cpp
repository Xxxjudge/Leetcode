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
        ListNode *current=head;
        while(current!=NULL&&current->next!=NULL) {
            if(current->val==current->next->val) {
                current->next=current->next->next;
                continue;
            }
            current=current->next;
        }
        return head;
    }
};