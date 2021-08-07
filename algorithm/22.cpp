class Solution {
public:
    void backtrack(vector<string>& ans,string temp,int left,int right,int n) {
        if(left+right==n+n) {
            ans.push_back(temp);
            return;
        }
        if(left<n) {
            temp+='(';
            backtrack(ans,temp,left+1,right,n);
            temp.pop_back();
        }
        if(right<left) {
            temp+=')';
            backtrack(ans,temp,left,right+1,n);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string temp;
        int index=0,left=0,right=0;
        backtrack(ans,temp,left,right,n);
        return ans;
    }
};