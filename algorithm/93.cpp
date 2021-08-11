class Solution {
public:
    void backtrack(vector<vector<int>>& res,vector<int> temp,int index,int n) { //转化为将N分成4份
        if(index==4&&accumulate(temp.begin(),temp.end(),0)==n) {
            res.push_back(temp);
        }
        for(int i=1;i<4;i++) {
            if(index==4) return;
            temp[index]=i;
            backtrack(res,temp,index+1,n);
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        int n=s.size();
        for(auto x:s) if(x<'0'||x>'9') return ans;
        if(n<4) return ans;
        vector<vector<int>> res;
        vector<int> temp(4);
        backtrack(res,temp,0,n);
        for(int i=0;i<res.size();i++) {
            string ss="";
            int pos=0;
            for(int j=0;j<res[0].size();j++) {
                if(res[i][j]>1&&s[pos]=='0') break;
                if(res[i][j]==3&&(stoi(s.substr(pos,3))>255)) break;
                if(j==3) {
                    ss+=s.substr(pos,res[i][j]);
                    pos+=res[i][j];
                }
                else {
                    ss+=s.substr(pos,res[i][j]);
                    ss+='.';
                    pos+=res[i][j];
                }
            }
            if(ss!=""&&pos==n) ans.push_back(ss);
        }
        return ans;
    }
};