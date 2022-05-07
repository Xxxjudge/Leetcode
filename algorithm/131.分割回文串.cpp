/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    void backtrack(vector<vector<string>>& ans,vector<string>& temp,vector<vector<bool>>& dp,string s,int index,int n) {
        if(index==n) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++) {
            if(dp[index][i]){
                temp.push_back(s.substr(index,i-index+1));
                backtrack(ans,temp,dp,s,i+1,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n,true));
        for(int i=n-1;i>=0;i--) 
            for(int j=i+1;j<n;j++)
                dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];

        vector<string> temp;
        backtrack(ans,temp,dp,s,0,n);
        return ans;
    }
};
// @lc code=end

