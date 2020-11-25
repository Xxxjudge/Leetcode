class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n));
        int left=0,right=n-1,top=0,bottom=n-1;
        int count=1;
        while(1) {
            for(int i=left;i<=right;i++) {
                ans[top][i]=count;
                count++;
            }
            top++;
            if(top>bottom) break;
            for(int i=top;i<=bottom;i++) {
                ans[i][right]=count;
                count++;
            }
            right--;
            if(right<left) break;
            for(int i=right;i>=left;i--) {
                ans[bottom][i]=count;
                count++;
            }
            bottom--;
            if(top>bottom) break;
            for(int i=bottom;i>=top;i--) {
                ans[i][left]=count;
                count++;
            }
            left++;
            if(right<left) break;
        }
    return ans;
    }
};