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
    ListNode* reverseList(ListNode* head) {
        //head是第一个元素，所有链表没有空的头，要自己加,下面为不用head的头插法
        if(!head) return head;
        ListNode* p=nullptr;//空头
        ListNode* q=head;
        ListNode* next;
        while(q) {
            next=q->next;
            q->next=p;
            p=q;
            q=next;
        }
        return p;
    }
};