/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */

// @lc code=start
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> n1;
        unordered_map<int,int> n2;
        vector<int> ans;
        for(int i=0;i<nums1.size();i++) ++n1[nums1[i]];
        for(int i=0;i<nums2.size();i++) ++n2[nums2[i]];
        for(auto it=n1.begin();it!=n1.end();it++) {
            if(n2.find(it->first)!=n2.end()) {
                int num=min(n1[it->first],n2[it->first]);
                for(int i=0;i<num;i++) ans.push_back(it->first);
            }
        }
        return ans;
    }
};
// @lc code=end

