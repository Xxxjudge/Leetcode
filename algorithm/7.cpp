class Solution {
public:
    int reverse(int x) {
        int pop;
        int ans=0;
        while(x!=0)
        {
            pop=x%10;
            if(ans>INT_MAX/10||(ans==INT_MAX/10&&pop>7))
                return 0;
            if(ans<INT_MIN/10||(ans==INT_MIN/10&&pop<-8))
                return 0;
            x=x/10;
            ans=ans*10+pop;
        }
        return ans;
    }
};
//以前写的，不记得了