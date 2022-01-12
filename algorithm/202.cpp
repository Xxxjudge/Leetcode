class Solution {
public:
    bool isHappy(int n) {
        for(int i=0;i<100;i++) {
            int ans=0;
            while(n>0) {
                ans+=(n%10)*(n%10);
                n/=10;
            }
            n=ans;
            if(n==1) return true;
        }
        return false;
    }
};//快乐数，我很快乐反正。100次还不能快乐，那就别快乐了！