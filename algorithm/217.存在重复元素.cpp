/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> myset;
        for(auto x:nums) {
            if(myset.find(x)!=myset.end()) {
                return true;
            }
            myset.insert(x);
        }
        return false;
    }
};
// @lc code=end

