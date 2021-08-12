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
    void reorderList(ListNode* head) {
        //先定位中间
        ListNode* fast,* slow;
        fast=slow=head;
        int odd=0;
        while(fast&&fast->next) {
            slow=slow->next;
            fast=fast->next->next;
        }

        //再反转slow后面的
        ListNode* p,*q;
        p=nullptr;
        q=slow;
        ListNode* next;
        while(q) {
            next=q->next;
            q->next=p;
            p=q;
            q=next;
        }
        //依次插入元素
        ListNode* temp=nullptr;
        ListNode* first=head,* second=p;
        while(second->next) {
            temp=first;
            first=first->next;
            temp->next=second;
            second=second->next;
            temp=temp->next;
            temp->next=first;
        }
    }
};