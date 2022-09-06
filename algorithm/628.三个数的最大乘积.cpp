/*
 * @lc app=leetcode.cn id=628 lang=cpp
 *
 * [628] 三个数的最大乘积
 */

// @lc code=start
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=nums[n-1];
        ans*=nums[1]*nums[0];
        return max(ans,nums[n-1]*nums[n-2]*nums[n-3]);
    }
};
// @lc code=end

