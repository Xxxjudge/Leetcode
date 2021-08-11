class Solution {
public:
    void backtrack(vector<vector<string>>& ans,vector<vector<int>>& nums,vector<int>& pos,int index,int n) {
        if(index==n) {
            vector<string> temp;
            for(int i=0;i<n;i++) {
                string s;
                for(int j=0;j<n;j++) {
                    if(nums[i][j]==0) s+='.';
                    else s+='Q';
                }
                temp.push_back(s);
            }
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++) {
            pos[index]=i;
            int tag=1;//表示可用
            for(int j=0;j<index;j++) {
                if(abs(pos[j]-pos[index])==abs(j-index)||i==pos[j]) {
                    tag=0;
                    break;
                }
            }
            if(tag==0) continue;
            nums[index][i]=1;
            backtrack(ans,nums,pos,index+1,n);
            nums[index][i]=0;
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> nums(n,vector<int>(n,0));
        vector<int> pos(n,0);
        backtrack(ans,nums,pos,0,n);
        return ans;
    }
};