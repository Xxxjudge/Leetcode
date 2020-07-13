class Solution {
public:
    bool isPalindrome(int x) {
        long y=0;
        int temp=x;
        while(temp){
            y=y*10+temp%10;
            temp/=10;
        }
        return y==x&&x>=0;
    }
};