/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */

// @lc code=start
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        for(int i=1;i<n+1;i++) {
            if(i%2==1) ans[i]=ans[i/2]+1;
            else ans[i]=ans[i/2];
        }
        return ans;
    }
};
// @lc code=end

