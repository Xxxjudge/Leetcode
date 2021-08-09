class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int> temp,vector<int>& nums,unordered_map<int,int>& m,int index,int n) {
        if(index==n) {
            ans.push_back(temp);
            return;
        }
        for(int i=0;i<n;i++) {
            if(m.at(nums[i])==1) {
                m.at(nums[i])=0;
                temp.push_back(nums[i]);
                backtrack(ans,temp,nums,m,index+1,n);
                temp.pop_back();
                m.at(nums[i])=1;
            }
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        if(n==1) {
            temp.push_back(nums[0]);
            ans.push_back(temp);
            return ans;
        }
        unordered_map<int,int> m;
        for(auto x:nums) m.emplace(x,1); 
        backtrack(ans,temp,nums,m,0,n);
        return ans;

    }
};