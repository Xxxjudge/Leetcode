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
	ListNode* swapPairs(ListNode* head) {
		if (head == NULL || head->next == NULL) return head;
		ListNode* p = head;
		ListNode* q = head->next;
		ListNode* dummyhead = new ListNode(0);
		dummyhead->next = head;
		ListNode* pos = dummyhead;
		while (p != NULL&&q != NULL) {
			pos->next = q;
			p->next = q->next;
			q->next = p;
			if (p->next != NULL) {
				pos = p;
				p = p->next;
				q = p->next;
			}
			else return dummyhead->next;
		}
		return dummyhead->next;
	}
};