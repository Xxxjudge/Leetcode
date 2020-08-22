class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        vector<vector<int>> flag(n,vector<int>(n,0));
        int num=1;
        int x=0,y=0,tx=0,ty=0;
        vector<int> diry={1,0,-1,0};
        vector<int> dirx={0,1,0,-1};
        int d=0;
        while(num<=n*n) {
            ans[x][y]=num++;
            flag[x][y]=1;
            tx=x+dirx[d];
            ty=y+diry[d];
            if(tx<0||tx>=n||ty<0||ty>=n||flag[tx][ty]==1) {
                d=(d+1)%4;
                tx=x+dirx[d];
                ty=y+diry[d];
            }
            x=tx;
            y=ty;
        }
        return ans;
    }
};
//定义方向