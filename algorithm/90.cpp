class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res={{}};
        map<int,int> num;
        for(auto i:nums) num[i]++;
        vector<int> temp;
        for(auto i:num) {
            int numsubset=res.size();
            for(int j=0;j<numsubset;j++) {
                temp=res[j];
                for(int k=0;k<i.second;k++) {
                    temp.push_back(i.first);
                    res.push_back(temp);
                }
            }
        }
    return res;
        
    }
};