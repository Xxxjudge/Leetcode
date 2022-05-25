/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        if(n==0||k==0) return 0;
        vector<vector<int>> buy(n,vector<int>(k));
        vector<vector<int>> sell(n,vector<int>(k));
        buy[0][0]=-prices[0];
        sell[0][0]=0;
        for(int i=1;i<k;i++) {
            buy[0][i]=-INT_MAX;
            sell[0][i]=-INT_MAX;
        }
        for(int i=1;i<n;i++) {
            for(int j=0;j<k;j++) {
                if(j>=1&&sell[i-1][j-1]>prices[i]-INT_MAX) buy[i][j]=max(buy[i-1][j],sell[i-1][j-1]-prices[i]);
                else if(j>=1&&sell[i-1][j-1]==-INT_MAX) buy[i][j]=buy[i-1][j];
                else buy[i][j]=max(buy[i-1][j],-prices[i]);
                sell[i][j]=max(sell[i-1][j],buy[i-1][j]+prices[i]);
            }
        }
        return *max_element(sell[n-1].begin(),sell[n-1].end());     
    }
};
// @lc code=end

