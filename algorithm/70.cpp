class Solution {
public:
    int climbStairs(int n) {
        if(n<1) return 0;
        if(n==1) return 1;
        int pre=0,ans=1;
        for(int i=0;i<n;i++) {
            ans+=pre;
            pre=ans-pre;
        }
        return ans;
    }
};
//斐波那契数列的应用，f0=1,f1=1,f2=f0+f1,f3=f1+f2则设置f0=pre,f1=ans;
//求f2=ans=ans+pre,再将pre设为f1的值，即为pre=ans-pre;