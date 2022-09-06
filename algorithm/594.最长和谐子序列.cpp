/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int begin=0;
        int ans=0;
        for(int end=0;end<nums.size();end++) {
            if(nums[end]-nums[begin]>1) begin++;
            if(nums[end]-nums[begin]==1) ans=max(ans,end-begin+1);
        }
        return ans;
    }
};
// @lc code=end

