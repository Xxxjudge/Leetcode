/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int i=1;
        ListNode* pre=new ListNode();
        pre->next=head;
        ListNode* p=head;
        ListNode* back=head;
        ListNode* ans=pre;
        while(i<=right+1) {
            if(i<left) {                
                if(i==left-1) {
                    pre=p;
                    back=pre->next;
                }
                p=p->next;
                i++;
            } else if(i<=right){
                ListNode* next=p->next;
                p->next=pre->next;
                pre->next=p;
                p=next;
                i++;
            } else {
                back->next=p;
                break;
            }
        }
        return ans->next;
    }
    }
};
// @lc code=end

