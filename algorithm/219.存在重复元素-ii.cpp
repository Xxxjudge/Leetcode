/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> mymap;
        for(int i=0;i<nums.size();i++) {
            if(mymap.find(nums[i])!=mymap.end()) {
                if(k>=(i-mymap[nums[i]])) return true;
                else mymap[nums[i]]=i;
            } else {
                mymap.insert({nums[i],i});
            }
        }
        return false;
    }
};
// @lc code=end

