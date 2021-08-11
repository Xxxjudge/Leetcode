class Solution {
public:
    void backtrack(int& ans,vector<vector<int>>& nums,vector<int>& pos,int index,int n) {
        if(index==n) {
            ans++;
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

    int totalNQueens(int n) {
        int ans=0;
        vector<vector<int>> nums(n,vector<int>(n,0));
        vector<int> pos(n,0);
        backtrack(ans,nums,pos,0,n);
        return ans;
    }
};