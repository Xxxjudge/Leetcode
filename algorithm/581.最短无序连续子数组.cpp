/*
 * @lc app=leetcode.cn id=581 lang=cpp
 *
 * [581] 最短无序连续子数组
 */

// @lc code=start
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> sorted=nums;
        sort(sorted.begin(),sorted.end());
        int left=0,right=nums.size()-1;
        while(left<right) {
            if(nums[left]==sorted[left]) {left++;continue;}
            if(nums[right]==sorted[right]) {right--;continue;}
            return right-left+1;
        }
        return 0;
    }
};
// @lc code=end

