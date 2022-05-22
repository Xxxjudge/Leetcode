/*
 * @lc app=leetcode.cn id=397 lang=cpp
 *
 * [397] 整数替换
 */

// @lc code=start
class Solution {
    int dfs(long n) {
        if(n==1) return 0;
        if(n==2) return 1;
        // if(n==(INT_MAX-1)) return dfs(n-1)+1;
        // if(n==(2147483647)) return dfs(n-1)+1;
        if(n%2==0) return dfs(n/2)+1;
        return min(dfs(n+1),dfs(n-1))+1;
    }
    int integerReplacement(int n) {
        // vector<int> dp(n+2);
        // dp[1]=0;
        // dp[2]=1;
        // for(int i=3;i<=n;i+=2) {
        //     dp[i+1]=dp[(i+1)/2]+1;
        //     dp[i-1]=dp[(i-1)/2]+1;
        //     dp[i]=min(dp[i+1],dp[i-1])+1;
        // }
        // return dp[n];
        //   dp超时！！换dfs
        return dfs(n);
    }
};
// @lc code=end

