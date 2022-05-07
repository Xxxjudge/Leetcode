/*
 * @lc app=leetcode.cn id=647 lang=cpp
 *
 * [647] 回文子串
 */

// @lc code=start
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int ans=0;
        vector<vector<bool>> dp(n,vector<bool>(n,true));
        for(int i=n-1;i>=0;i--) 
            for(int j=i+1;j<n;j++)
                dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
        for(int i=0;i<n;i++)
            for(int j=i;j<n;j++)
                if(dp[i][j]) ans++;
        return ans;
    }
};
// @lc code=end

