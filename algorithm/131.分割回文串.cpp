/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
class Solution {
public:
    bool isPartition(string s) {
        int n=s.size();
        if(n<=1) return true;
        int mid=n/2;
        if(n%2==0) {
            int left=mid-1,right=mid;
            while(left!=-1) {
                if(s[left]!=s[right]) return false;
                left--;
                right++;
            }
        } else {
            int left=mid-1,right=mid+1;
            while(left!=-1) {
                if(s[left]!=s[right]) return false;
                left--;
                right++;
            }
        }
        return true;
    }

    void backtrack(vector<vector<string>>& ans,vector<string>& temp,vector<vector<bool>>& dp,string s,int index,int n) {
        if(index==n) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++) {
            if(dp[index][i+1]){
                temp.push_back(s.substr(index,i-index+1));
                backtrack(ans,temp,dp,s,i+1,n);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        int n=s.size();
        vector<vector<bool>> dp(n,vector<bool>(n+1,false));
        for(int i=0;i<n;i++) 
            for(int j=i+1;j<n+1;j++)
                if(isPartition(s.substr(i,j-i))) dp[i][j]=true;
        vector<string> temp;
        backtrack(ans,temp,dp,s,0,n);
        return ans;
    }
};
// @lc code=end

