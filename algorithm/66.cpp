class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        if(m==0||n==0) return 0;
        vector<vector<int>> mins(m,vector<int>(n,0));
        mins[0][0]=grid[0][0];
        for(int i=1;i<n;i++) mins[0][i]=mins[0][i-1]+grid[0][i];
        for(int i=1;i<m;i++) mins[i][0]=mins[i-1][0]+grid[i][0];
        for(int i=1;i<m;i++)
            for(int j=1;j<n;j++) 
                mins[i][j]=min(mins[i-1][j],mins[i][j-1])+grid[i][j];
        return mins[m-1][n-1];
    }
};