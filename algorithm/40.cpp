class Solution {
public:
    vector<int> temp;
    vector<vector<int>> ans;
    void backtracking(vector<int>& candidates,int sum,int target,int index,vector<bool>& used) {
        if(sum==target) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size()&&(sum+candidates[i]<=target);i++) {
            if(i>0&&used[i-1]==false&&candidates[i]==candidates[i-1]) 
                 continue;
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            used[i]=true;
            backtracking(candidates,sum,target,i+1,used);
            used[i]=false;
            temp.pop_back();
            sum-=candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<bool> used(candidates.size(),false);
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,0,target,0,used);
        return ans;
    }
};