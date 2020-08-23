class Solution {
public:
    string getPermutation(int n, int k) {
        string ans="";
        string s=string("123456789").substr(0,n);
        int i=n;
        k--;
        while(i!=0) {
            ans+=s[(k)/f(i-1)];
            s.erase(s.begin()+(k)/f(i-1));
            k=k%f(i-1);
            i--;
        }
        return ans;
    }
    int f(int n) {
        int ans=1;
        for(int i=1;i<=n;i++) ans*=i;
        return ans;
    }
};