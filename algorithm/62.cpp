class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1||n==1) return 1;
        int num=m+n-2;
        long ans=1;
        int a=(m>n)?n-1:m-1;
        for(int i=1;i<=a;i++,num--) ans=ans*num/i;
        return ans;
    }
};
//简单的数学题