class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        int p=0,q=0;
        string temp=dominoes;
        string dot(n,'.');
        temp.insert(0,dot);
        temp+=dot;
        string ans="";
        for(int i=n;i<n+n;i++) {
            if(temp[i]!='.') {
                ans+=temp[i];
                continue;
            }
            p=i-1;
            q=i+1;
            while(p>=0&&q<=n+n+n) {
                if(temp[p]=='.'&&temp[q]=='.') {p=p-1;q=q+1;}
                else if((temp[p]=='.'||temp[p]=='L')&&temp[q]=='L') {ans+='L';break;}
                else if(temp[p]=='.'&&temp[q]=='R') {p--;}
                else if(temp[p]=='L'&&temp[q]=='.') {q++;}
                else if(temp[p]=='R'&&(temp[q]=='.'||temp[q]=='R')) {ans+='R';break;}
                else if(temp[p]=='R'&&temp[q]=='L') {ans+='.';break;}
                else if(temp[p]=='L'&&temp[q]=='R') {ans+='.';break;}
                else {p=p-1;q=q+1;}
            }
            if(p<0||q>n+n+n) ans+='.';             
        }
        return ans;        
    }
};