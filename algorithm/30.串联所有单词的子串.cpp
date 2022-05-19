/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    bool isSub(unordered_map<string,int> mymap,vector<string>& words,string s,int wordlength,int length) {
        for(int i=0;i<length;i+=wordlength){
            string temp=s.substr(i,wordlength);
            if(mymap.find(temp)!=mymap.end()) {
                if(mymap[temp]!=0) {
                    mymap[temp]--;
                    continue;
                }
            }
            return false;
        }
        return true;
    }
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> mymap;
        
        int wordlength=words[0].size();
        for(auto x:words) {
            if(mymap.find(x)==mymap.end())
                mymap.insert({x,1});
            else mymap[x]+=1;
        }
        int n=words.size();
        int length=n*wordlength;
        vector<int> ans;
        if(s.size()<length) return ans;
        for(int i=0;i<=s.size()-length;i++){
            if(isSub(mymap,words,s.substr(i,length),wordlength,length)) {
                ans.push_back(i);
            }
        }
        return ans;       
    }
};
// @lc code=end

