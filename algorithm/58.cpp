class Solution {
public:
    int lengthOfLastWord(string s) {
        if(s.size()==0) return 0;
        int count=0,end=s.size()-1;
        for(int i=s.size()-1;i>=0;i--) {
            if(s[i]!=' ') {
                end=i;
                break;
            }
        }
        for(auto x:s.substr(0,end+1)) {
            count++;
            if(x==' ') count=0;
        }
        return count;
    }
};