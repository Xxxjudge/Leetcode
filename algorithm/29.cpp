class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==0) return 0;
        if(divisor==1) return dividend;
        if(divisor==-1) {
            if(dividend>INT_MIN) return -dividend;
            else return INT_MAX;
        }
        //判断符号
        int sign=1;
        if((dividend>0&&divisor<0)||(dividend<0&&divisor>0)) sign=-1;
        long a=dividend;
        long b=divisor;
        a=a>0?a:-a;
        b=b>0?b:-b;
        if(sign==1) return div(a,b);
        else return (div(a,b)==INT_MIN)?INT_MAX:-div(a,b);
    }
    int div(long a,long b) {
        int ans=1;
        long temp=b;
        if(a<b) return 0;
        while(a>=temp+temp) {
            ans=ans+ans;
            temp=temp+temp;
        }
        return ans+div(a-temp,b);
    }
};