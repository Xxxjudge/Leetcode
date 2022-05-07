/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        int ans=n;
        vector<vector<bool>> dp(n,vector<bool>(n,true));
        for(int i=n-1;i>=0;i--) 
            for(int j=i+1;j<n;j++)
                dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
        vector<int> minCount(n);
        minCount[0]=0;
        for(int i=1;i<n;i++) {
            minCount[i]=minCount[i-1]+1;
            if(dp[0][i]) {minCount[i]=0;continue;}
            for(int j=1;j<i;j++) {
                if(dp[j][i]) minCount[i]=min(minCount[i],minCount[j-1]+1);
            }
            // cout<<minCount[i]<<' ';
        }
        return minCount[n-1];
    }
};
// @lc code=end

