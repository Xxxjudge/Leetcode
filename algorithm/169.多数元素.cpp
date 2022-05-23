/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> mymap;
        for(auto x:nums) {
            ++mymap[x];
            ans=mymap[x]>mymap[ans]?x:ans;
        }
        return ans;
    }
};
// @lc code=end

