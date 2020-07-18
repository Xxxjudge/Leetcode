class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        if(strs.empty()) return ans;//为空则返回空
        if(strs.size()==1) return strs[0];//仅有一个元素则返回这个
        for(int i=0;i<strs[0].size();i++) {
            for(int j=0;j<strs.size()-1;j++) {
                if(strs[j][i]!=strs[j+1][i]) return ans;
                else if(j==strs.size()-2) ans+=strs[j][i];
            }
        }
        return ans;
    }
};