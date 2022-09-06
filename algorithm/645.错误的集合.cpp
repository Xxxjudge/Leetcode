/*
 * @lc app=leetcode.cn id=645 lang=cpp
 *
 * [645] 错误的集合
 */

// @lc code=start
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans(2);
        int sum=0;
        for(int i=1;i<=nums.size();i++) {
            sum+=i;
            sum-=nums[i-1];
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]==nums[i+1]) {
                ans[0]=nums[i];
                ans[1]=nums[i]+sum;
            }
        }
        return ans;
    }
};
// @lc code=end

