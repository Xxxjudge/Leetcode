/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
public:
    unordered_map<char,int> mymap,temp;
    bool check() {
        for(const auto& p:mymap) {
            if(temp[p.first]<p.second) return false;
        }
        return true;
    }
    string minWindow(string s, string t) {
        
        if(s.size()<t.size()) return "";
        for(int i=0;i<t.size();i++) {
            if(mymap.find(t[i])!=mymap.end()){
                mymap[t[i]]++;
            } else {
                mymap.insert({t[i],1});
            }
        }
        int l=0,r=0;
        int minlength=s.size();
        string ans="";
        while(r<s.size()) {
            if(mymap.find(s[r])!=mymap.end()) {
                ++temp[s[r]];
                if(check()) {
                    while(l<=r) {
                        if(temp.find(s[l])!=temp.end()) temp[s[l]]--;
                        else {l++;continue;}
                        if(check()) l++;
                        else {
                            if(r-l+1<=minlength) {
                                minlength=r-l+1;
                                ans=s.substr(l,minlength);
                            }
                            l++;
                            break;
                        }
                    }
                } 
            } 
            r++;
        }
        return ans;

    }
};
// @lc code=end

