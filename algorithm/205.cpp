class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> scode(128,0);
        vector<int> tcode(128,0);
        int n=s.size();
        for(int i=0;i<s.size();i++) {
            if(scode[(int)s[i]]==0) scode[(int)s[i]]=i+1;
            else scode[(int)s[i]]+=n;
            if(tcode[(int)t[i]]==0) tcode[(int)t[i]]=i+1;
            else tcode[(int)t[i]]+=n;
            if((int)scode[s[i]]!=tcode[(int)t[i]]) return false;
        }
        return true;
    }
};