/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int slow=0,fast=0;
        for(;fast<nums.size();fast++) {
            if(nums[fast]!=0) {
                swap(nums[slow++],nums[fast]);
            }
        }
    }
};
// @lc code=end

