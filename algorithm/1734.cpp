class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n=encoded.size()+1;
        vector<int> perm(n);
        int total=0,odd=0;
        for(int i=1;i<=n;i++) total^=i;
        for(int i=1;i<n-1;i+=2) odd^=encoded[i];
        perm[0]=total^odd;
        for(int i=1;i<n;i++) perm[i]=encoded[i-1]^perm[i-1]; 
        return perm;
    }
};