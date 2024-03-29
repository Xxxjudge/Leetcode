/*
 * @lc app=leetcode.cn id=376 lang=cpp
 *
 * [376] 摆动序列
 */

// @lc code=start
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n=nums.size();
        vector<int> up(n,1);
        vector<int> down(n,1);
        for(int i=1;i<n;i++) {
            if(nums[i]>nums[i-1]) {
                up[i]=max(up[i-1],down[i-1]+1);
                down[i]=down[i-1];
            } else if(nums[i]<nums[i-1]) {
                down[i]=max(down[i-1],up[i-1]+1);
                up[i]=up[i-1];
            } else {
                down[i]=down[i-1];
                up[i]=up[i-1];
            }   
        }
        return max(up[n-1],down[n-1]);
    }
};
// @lc code=end

