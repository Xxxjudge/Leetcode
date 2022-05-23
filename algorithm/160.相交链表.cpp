/*
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

// @lc code=start
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pa,*pb;
        pa=headA;
        pb=headB;
        while(pa!=NULL&&pb!=NULL) {
            pa=pa->next;
            pb=pb->next;
        }
        if(pa==NULL) {
            pa=headB;
            while(pb!=NULL) {
                pa=pa->next;
                pb=pb->next;
            }
            pb=headA;
        } else if(pb==NULL) {
            pb=headA;
            while(pa!=NULL) {
                pa=pa->next;
                pb=pb->next;
            }
            pa=headB;
        }
        while(pa!=NULL&&pb!=NULL) {
            if(pa==pb) return pa;
            pa=pa->next;
            pb=pb->next;

        }
        return NULL;
    }
};
// @lc code=end

