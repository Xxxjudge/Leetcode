class Solution {
public:
    string addBinary(string a, string b) {
        int count=0;
        string ans="";
        int na=a.size(),nb=b.size();
        while(na<nb) {
            a='0'+a;
            na++;
        }
        while(na>nb) {
            b='0'+b;
            nb++;
        }
        for(int i=na-1;i>=0;i--) {
            char temp=a[i]-'0'+b[i]+count;
            if(temp>='2') {
                count=1;
                temp-=2;
                ans=temp+ans;
            } else {
                count=0;
                ans=temp+ans;
            }
        }
        if(count==1) ans='1'+ans;
        return ans;
    }
};