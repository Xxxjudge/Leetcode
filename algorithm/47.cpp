class Solution {
public:
    void backtrack(vector<vector<int>>& ans,vector<int> temp,unordered_map<int,int>& m,int index,int n) {
        if(index==n) {
            ans.push_back(temp);
            return;
        }
        for(auto it=m.begin();it!=m.end();it++) {
            if(it->second>0) {
                it->second--;
                temp.push_back(it->first);
                backtrack(ans,temp,m,index+1,n);
                temp.pop_back();
                it->second++;
            }
        }

    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        int n=nums.size();
        if(n==1) {
            temp.push_back(nums[0]);
            ans.push_back(temp);
            return ans;
        }
        unordered_map<int,int> m;
        for(auto x:nums) {
            if(m.find(x)!=m.end()) {
                m.at(x)++;
            } else {
                m.emplace(x,1);
            }
        } 
        backtrack(ans,temp,m,0,n);
        return ans;
    }
};