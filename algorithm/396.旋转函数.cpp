/*
 * @lc app=leetcode.cn id=396 lang=cpp
 *
 * [396] 旋转函数
 */

// @lc code=start
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n=nums.size();
        int numsum=0;
        vector<int> F(n,0);
        for(int i=0;i<n;i++) {
            numsum+=nums[i];
            F[0]+=i*nums[i];
        }
        for(int i=1;i<n;i++) {
            F[i]=F[i-1]+numsum-n*nums[n-i];
        }
        return *max_element(F.begin(),F.end());
    }
};
// @lc code=end

