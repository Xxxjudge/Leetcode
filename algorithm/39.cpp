class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;

    void backtracking(vector<int>& candidates,int target,int sum,int index) {
        if(sum==target) {
            ans.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size()&&(sum+candidates[i]<=target);i++) {
            sum+=candidates[i];
            temp.push_back(candidates[i]);
            backtracking(candidates,target,sum,i);
            sum-=candidates[i];
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        backtracking(candidates,target,0,0);
        return ans;
    }
};