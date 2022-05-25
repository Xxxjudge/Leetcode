/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        vector<int> nums1,nums2;
        while(l1!=NULL) {
            nums1.push_back(l1->val);
            l1=l1->next;
        }
        while(l2!=NULL) {
            nums2.push_back(l2->val);
            l2=l2->next;
        }
        if(nums1.size()>nums2.size()) {
            int count=0;
            vector<int> ans(nums1.size());
            int i=nums1.size()-1;
            int j=nums2.size()-1;
            while(j>=0) {
                ans[i]=(nums1[i]+nums2[j]+count)%10;
                count=(nums1[i]+nums2[j]+count)/10;
                i--;j--;
            }
            while(i>=0) {
                ans[i]=(nums1[i]+count)%10;
                count=(nums1[i]+count)/10;
                i--;
            }
            if(count!=0) ans.insert(ans.begin(),count);
                    ListNode* head=new ListNode(0,NULL);
        for(int i=ans.size()-1;i>=0;i--) {
            ListNode* p=new ListNode(ans[i],head->next);
            head->next=p;
        }
        return head->next;
        } else {
            int count=0;
            vector<int> ans(nums2.size());
            int i=nums1.size()-1;
            int j=nums2.size()-1;
            while(i>=0) {
                ans[j]=(nums1[i]+nums2[j]+count)%10;
                count=(nums1[i]+nums2[j]+count)/10;
                i--;j--;
                
            }
            while(j>=0) {
                ans[j]=(nums2[j]+count)%10;
                count=(nums2[j]+count)/10;
                j--;
            }
            if(count!=0) ans.insert(ans.begin(),count);
                    ListNode* head=new ListNode(1,NULL);
        for(int i=ans.size()-1;i>=0;i--) {
            ListNode* p=new ListNode(ans[i],head->next);
            head->next=p;
        }
        return head->next;
        }
    }
};
// @lc code=end

