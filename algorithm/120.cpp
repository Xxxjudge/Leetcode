class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int m=triangle.size();
        int n=triangle[m-1].size();
        vector<vector<int>> dp=triangle;
        for(int i=m-2;i>=0;i--)
            for(int j=0;j<n-(m-1-i);j++)
                dp[i][j]=min(dp[i+1][j],dp[i+1][j+1])+dp[i][j];
        return dp[0][0];
        
    }
};