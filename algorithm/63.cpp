class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size(),n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1||obstacleGrid[m-1][n-1]) return 0;
        vector<vector<int>> a(m,vector<int>(n,1));
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++) {
                if(obstacleGrid[i][j]==1) a[i][j]=0;
                else if(i==0&&j!=0) a[i][j]=a[i][j-1];
                else if(j==0&&i!=0) a[i][j]=a[i-1][j];
                else if(i==0&&j==0) a[0][0]=1;
                else a[i][j]=a[i-1][j]+a[i][j-1];
            }
        return a[m-1][n-1];
    }
};