class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1=0,v2=0;
        int n1=version1.size(),n2=version2.size();

        int i=0,j=0;
        while(i<n1||j<n2){
            int x=0;
            for(;i<n1&&version1[i]!='.';i++) {
                x=x*10+version1[i]-'0';
            }
            i++;
            int y=0;
            for(;j<n2&&version2[j]!='.';j++) {
                y=y*10+version2[j]-'0';
            }
            j++;
            if(x!=y)
            return x>y?1:-1;
        }
        return 0;
    }
};