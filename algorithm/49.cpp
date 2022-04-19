class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        int n=strs.size();

        if(n<=1) {ans.push_back(strs);return ans;}
        unordered_map<string,vector<string>> mymap;
        for(auto str:strs) {
            string key=str;
            sort(str.begin(),str.end());
            mymap[str].push_back(key);

        } 
        for(auto it=mymap.begin();it!=mymap.end();it++) ans.push_back(it->second);
        return ans;

    }
};