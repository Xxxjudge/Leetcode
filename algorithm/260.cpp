class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        vector<int> ans;
        unordered_map<int,int> myMap;
        for(auto x:nums) {
            if(myMap.find(x)==myMap.end()) myMap.insert(make_pair(x,1));
            else myMap[x]++;
        }
        for(auto x:myMap) if(x.second==1) ans.push_back(x.first);
        return ans;
    }
};
//简单的哈希表