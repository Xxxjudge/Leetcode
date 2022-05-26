/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */

// @lc code=start
class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1;
        vector<int> ans;
        for(auto x:nums1) n1.insert(x);
        for(auto x:nums2) if(n1.find(x)!=n1.end()) {
            ans.push_back(x);
            n1.erase(x);
        }
        return ans;
    }
};
// @lc code=end

