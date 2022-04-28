/*
 * @lc app=leetcode.cn id=1653 lang=cpp
 *
 * [1653] 使字符串平衡的最少删除次数
 */

// @lc code=start
class Solution {
public:
    int minimumDeletions(string s) {
        int n=s.size();
        int countb=0;
        if(s[0]=='b') countb++;
        vector<int> dp(n);
        dp[0]=0;
        for(int i=1;i<n;i++) {
            if(s[i]=='a') {
                dp[i]=min(dp[i-1]+1,countb);
            } else {
                dp[i]=dp[i-1];
                countb++;
            }
        }
        return dp[n-1];
    }
};
// @lc code=end

